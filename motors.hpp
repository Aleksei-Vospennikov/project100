#ifndef MOTORS_HPP
#define MOTORS_HPP

struct DrivingPin {
  int entrance_;
  int mode1_;
  int mode2_;

  DrivingPin (int entrance, int mode1, int mode2) : 
    entrance_{entrance}, mode1_{mode1}, mode2_{mode2} {
      pinMode(entrance_, OUTPUT);
      pinMode(mode1_, OUTPUT);
      pinMode(mode2_, OUTPUT);
    }

  void DrivingMotorRotate(int speed) {  
    analogWrite(entrance_, speed);
    digitalWrite(mode1_, HIGH);
    digitalWrite(mode2_, LOW);
  }
};

struct Motors {
  DrivingPin first_;
  DrivingPin second_;

  Motors (int first_entr, int first_m1, int first_m2,
          int second_entr, int second_m1, int second_m2) :
          first_{first_entr, first_m1, first_m2},
          second_(second_entr, second_m1, second_m2) {}

  void DrivingMotorsRotate(int speed) {  
    first_.DrivingMotorRotate(speed);
    second_.DrivingMotorRotate(speed);
  }
};

#endif // MOTORS_HPP