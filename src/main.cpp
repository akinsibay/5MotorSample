#include <AccelStepper.h>
long int aStepSayisi, bStepSayisi, cStepSayisi, dStepSayisi, eStepSayisi;
float aHiz, bHiz, cHiz, dHiz, eHiz;
String baslaMsg;
char buf[1000];
int i = 0;
char *data[10];
bool newData;
AccelStepper stepperA(1, 32, 33);
AccelStepper stepperB(1, 50, 52);
AccelStepper stepperC(1, 30, 31);
AccelStepper stepperD(1, 24, 25);
AccelStepper stepperE(1, 26, 27);
void setup()
{
  Serial.begin(9600);
  stepperA.enableOutputs();
  stepperB.enableOutputs();
  stepperC.enableOutputs();
  stepperD.enableOutputs();
  stepperE.enableOutputs();

  stepperA.setAcceleration(3333.0);
  //stepperA.setCurrentPosition(0);

  stepperB.setAcceleration(3333.0);
  //stepperB.setCurrentPosition(0);

  stepperC.setAcceleration(3333.0);
  //stepperC.setCurrentPosition(0);

  stepperD.setAcceleration(3333.0);
  //stepperD.setCurrentPosition(0);

  stepperE.setAcceleration(3333.0);
  //stepperE.setCurrentPosition(0);

  //Serial.println("selam");
}

void loop()
{
  stepperA.run();
  stepperB.run();
  stepperC.run();
  stepperD.run();
  stepperE.run();
  if (Serial.available() > 0)
  {
    baslaMsg = Serial.readString();
    newData = true;
    baslaMsg.toCharArray(buf, 1000);
    char *p = strtok(buf, "*");
    while (p != NULL)
    {
      data[i++] = p;
      p = strtok(NULL, "*");
      delay(50);

      aHiz = atof(data[0]);
      aStepSayisi = atol(data[1]);

      bHiz = atof(data[2]);
      bStepSayisi = atol(data[3]);

      cHiz = atof(data[4]);
      cStepSayisi = atol(data[5]);

      dHiz = atof(data[6]);
      dStepSayisi = atol(data[7]);

      eHiz = atof(data[8]);
      eStepSayisi = atol(data[9]);

      Serial.println(aStepSayisi);
      delay(50);
      //Serial.println(aStepSayisi);
    }
    if (newData == true)
    {
      stepperA.setMaxSpeed(aHiz);
      stepperA.move(aStepSayisi);

      stepperB.setMaxSpeed(bHiz);
      stepperB.move(bStepSayisi);

      stepperC.setMaxSpeed(cHiz);
      stepperC.move(cStepSayisi);

      stepperD.setMaxSpeed(dHiz);
      stepperD.move(dStepSayisi);

      stepperE.setMaxSpeed(eHiz);
      stepperE.move(eStepSayisi);
      newData = false;
    }
  }
}
