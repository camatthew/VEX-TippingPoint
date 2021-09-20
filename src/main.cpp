#include <list>
#include "main.h"
#include "motors.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor left_front_wheel (LEFT_FRONT_WHEELS_PORT, true); // This reverses the motor
pros::Motor left_back_wheel (LEFT_BACK_WHEELS_PORT);
pros::Motor right_front_wheel (RIGHT_FRONT_WHEELS_PORT);
pros::Motor right_back_wheel (RIGHT_BACK_WHEELS_PORT, true); // This reverses the motor
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
void moveWheels(double left_voltage, double right_voltage){
		left_front_wheel.move(left_voltage);
		left_back_wheel.move(left_voltage);
		right_front_wheel.move(right_voltage);
		right_back_wheel.move(right_voltage);
}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

	pros::lcd::print(1, "Bombexploding in 3");
	pros::delay(1000);
	pros::lcd::print(1, "Bombexploding in 2");
	pros::delay(1000);
	pros::lcd::print(1, "Bombexploding in 1");
	pros::delay(1000);
	pros::lcd::print(1, "You are dead");
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
int speedControl;
void opcontrol() {

  pros::c::adi_pin_mode(2, INPUT);
	pros::ADIDigitalIn button (DIGITAL_SENSOR_PORT);

	while (true) {
		pros::lcd::print(2, "LimitSwitch ->%d<-", pros::c::adi_digital_read(2));
    pros::lcd::print(3, "button ->%d<-", button.get_value());

		left_front_wheel.move(master.get_analog(ANALOG_LEFT_Y));
		left_back_wheel.move(master.get_analog(ANALOG_LEFT_Y));
		right_front_wheel.move(master.get_analog(ANALOG_RIGHT_Y));
		right_back_wheel.move(master.get_analog(ANALOG_RIGHT_Y));
		    pros::delay(2);
		}
	}
}
