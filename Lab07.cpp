/*************************************************************
 * 1. Name:
 *      Wade Withers, Ara Araujo
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was completing the set up correctly for each unit test.
 * 5. How long did it take for you to complete the assignment?
 *      About 3 hours.
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "howitzer.h"   // Howitzer

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      ground(ptUpperRight),
      time(0.0),
      angle(0.0),
      howitzer()
   {
      // Set the horizontal position of the howitzer. This should be random.
      howitzer.setPixelX(random(20,680));

      // Generate the ground and set the vertical position of the howitzer.
      ground.reset(howitzer.getPosition());

      // This is to make the bullet travel across the screen. Notice how there are 
      // 20 pixels, each with a different age. This gives the appearance
      // of a trail that fades off in the distance.
//      for (int i = 0; i < 20; i++)
//      {
//         projectilePath[i].setPixelsX((double)i * 2.0);
//         projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);
//      }
   }

   bool hitTheTarget(const Position& pos) const{
       if(abs(ground.getTarget().getMetersY() - pos.getMetersY()) <= 500.0 && (abs(ground.getTarget().getMetersX() - pos.getMetersX()) <= 500.0))
           return true;
       return false;
   }

   Ground ground;                 // the ground
//   Position  projectilePath[20];  // path of the projectile
   Howitzer howitzer;
   Position  ptUpperRight;        // size of the screen
   double angle;                  // angle of the howitzer 
   double time;                   // amount of time since the last firing
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move a large amount
   if (pUI->isRight())
      pDemo->howitzer.moveMuzzle(0.05);
   if (pUI->isLeft())
      pDemo->howitzer.moveMuzzle(-0.05);

   // move by a little
   if (pUI->isUp())
      pDemo->howitzer.moveMuzzle(pDemo->howitzer.getAngle().getRadians() >= 0 ? -0.003 : 0.003);
   if (pUI->isDown())
      pDemo->howitzer.moveMuzzle(pDemo->howitzer.getAngle().getRadians() >= 0 ? 0.003 : -0.003);

   // fire that gun
   if (pUI->isSpace()){
       pDemo->time = 0.0;
       if (pDemo->howitzer.getProjectile() == nullptr)
           pDemo->howitzer.fireProjectile();
   }

   //
   // perform all the game logic
   //

   // advance time by half a second.
   pDemo->time += 0.5;

   ogstream gout(Position(10.0, pDemo->ptUpperRight.getPixelsY() - 20.0));

   // draw the ground first
   pDemo->ground.draw(gout);

   // draw the howitzer
   gout.drawHowitzer(pDemo->howitzer.getPosition(), pDemo->howitzer.getAngle().getRadians(), pDemo->time);

   // draw the projectile
   if (pDemo->howitzer.getProjectile() != nullptr){
//       for (int i = 0; i < 20; i++)
//           gout.drawProjectile(pDemo->projectilePath[i], 0.5 * (double)i);
       pDemo->howitzer.updateProjectilePosition();
       if(pDemo->hitTheTarget(pDemo->howitzer.getProjectile()->getPosition())){
           pDemo->howitzer.resetProjectile();
           pDemo->ground.reset(pDemo->howitzer.getPosition());
       }
       else if(pDemo->ground.getElevationMeters(pDemo->howitzer.getProjectile()->getPosition()) > pDemo->howitzer.getProjectile()->getPosition().getMetersY()) {
           pDemo->howitzer.resetProjectile();
       }else{
           gout.drawProjectile(pDemo->howitzer.getProjectile()->getPosition(), 0.5 * double(1)); // comment this if we can't get it to work.
       }
   }

   // draw some text on the screen

   if (pDemo->howitzer.getProjectile() == nullptr){
       gout.setPosition(Position(22000.0,18000.0));
       gout << "Angle: " << pDemo->howitzer.getAngle().getDegrees() << " degree\n";
   }else{
       gout.setPosition(Position(22000.0,18000.0));
       gout << "altitude: " << pDemo->howitzer.getProjectile()->getPosition().getMetersY() << "m\n";
       gout.setPosition(Position(22000.0,17000.0));
       gout << "speed: " << pDemo->howitzer.getProjectile()->getVelocity().getVelocity() << "m/s\n";
       gout.setPosition(Position(22000.0,16000.0));
       gout << "distance: " << pDemo->howitzer.getProjectile()->getPosition().getMetersX() - pDemo->howitzer.getPosition().getMetersX() << "m\n";
       gout.setPosition(Position(22000.0,15000.0));
       gout << "hang time: " << pDemo->time << "s\n";
   }

}


double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    // Run unit tests.

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);

   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);

   return 0;
}
