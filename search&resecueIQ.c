#pragma config(Sensor, port2,  touchLED,       sensorVexIQ_LED)
#pragma config(Sensor, port3,  colorDetector,  sensorVexIQ_ColorHue)
#pragma config(Sensor, port4,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port7,  distanceMM,     sensorVexIQ_Distance)
#pragma config(Sensor, port8,  bumpSwitch,     sensorVexIQ_Touch)
#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Motor,  motor10,         armMotor,      tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor11,         clawMotor,     tmotorVexIQ, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
	repeat (4) {
		//// if empty room
		if (getDistanceValue(distanceMM) >= 300 && getColorValue(touchLED)== 255) {
			setMultipleMotors(50, motor1, motor6, , );
			waitUntil (getDistanceValue(distanceMM) <= 530);
			stopAllMotors();
			setTouchLEDColor(touchLED, colorOrange);
			if (getColorHue(colorDetector) == 36) {
				wait(5, seconds);
			} else {
				//// turn left
				resetGyro(port4);
				setMotor(motor1, -50);
				setMotor(motor6, 50);
				waitUntil (getGyroDegrees(gyroSensor) >= 90);
				stopAllMotors();
			}
		} else {
		/*	if (getDistanceValue(distanceMM) <= 200) {
				//// if not empty turn left - forward - turn right - forward - left
				// turn left
				resetGyro(port4);
				setMotor(motor1, -50);
				setMotor(motor6, 50);
				waitUntil (getGyroDegrees(gyroSensor) >= 90);
				stopAllMotors();
				// fowrard
				forward(2.2, rotations, 50);
				// turn right
				resetGyro(port4);
				setMotor(motor1, 50);
				setMotor(motor6, -50);
				waitUntil (getGyroDegrees(gyroSensor) <= -90);
				stopAllMotors();
				// forward
				forward(2.2, rotations, 50);
				// turn left
				resetGyro(port4);
				setMotor(motor1, -50);
				setMotor(motor6, 50);
				waitUntil (getGyroDegrees(gyroSensor) >= 90);
				stopAllMotors();
			} else {
				stopAllMotors();
			}
		}
	}*/
}
}
}
