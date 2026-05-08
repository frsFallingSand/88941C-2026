#include "robot-cfg.h"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/abstract_motor.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup mg_left({14, 15, 16}, pros::MotorGear::ratio_6_to_1);
pros::MotorGroup mg_right({-18, -19, -20}, pros::MotorGear::ratio_6_to_1);

pros::Imu imu(21);

lemlib::Drivetrain dt(&mg_left, &mg_right,
                      10,                         // 10 inch track width
                      lemlib::Omniwheel::NEW_325, // using new 4" omnis
                      450,                        // drivetrain rpm is 360
                      2 // horizontal drift is 2 (for now)
);

lemlib::OdomSensors os(nullptr, // vertical tracking wheel 1, set to null
                       nullptr,
                       nullptr, // horizontal tracking wheel 1
                       nullptr, &imu);

// lateral PID controller
lemlib::ControllerSettings lc(10,  // proportional gain (kP)
                              0,   // integral gain (kI)
                              3,   // derivative gain (kD)
                              3,   // anti windup
                              1,   // small error range, in inches
                              100, // small error range timeout, in milliseconds
                              3,   // large error range, in inches
                              500, // large error range timeout, in milliseconds
                              20   // maximum acceleration (slew)
);
// angular PID controller
lemlib::ControllerSettings ac(0.5, // proportional gain (kP)
                              0,   // integral gain (kI)
                              0,   // derivative gain (kD)
                              3,   // anti windup
                              1,   // small error range, in degrees
                              100, // small error range timeout, in milliseconds
                              3,   // large error range, in degrees
                              500, // large error range timeout, in milliseconds
                              0    // maximum acceleration (slew)
);

lemlib::Chassis c(dt, lc, ac, os);
