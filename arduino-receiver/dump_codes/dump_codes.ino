#include <IRLib.h>
 
IRrecv My_Receiver(11); //connect the receiver to pin 11
 
IRdecode My_Decoder;

int c = 0;

void setup()
{
  Serial.begin(9600);
  My_Receiver.enableIRIn(); // Start the receiver
}
 
void loop()
{

//Continuously look for results. When you have them pass them to the decoder
  if (My_Receiver.GetResults(&My_Decoder)) {
    Serial.print("Sample nr.");
    Serial.print(c++);
    Serial.print("\n");
    My_Decoder.decode();    //Decode the data
    My_Decoder.DumpResults(); //Show the results on serial monitor
    My_Receiver.resume();     //Restart the receiver
  }
}


// /* comboDump.ino Example sketch for IRLib2
//  *  Illustrate how to create a custom decoder using only the protocols
//  *  you wish to use.
//  */
// #include <IRLibDecodeBase.h> // First include the decode base
// #include <IRLib_P01_NEC.h>   // Now include only the protocols you wish
// #include <IRLib_P02_Sony.h>  // to actually use. The lowest numbered
// #include <IRLib_P07_NECx.h>  // must be first but others can be any order.
// #include <IRLib_P09_GICable.h>
// #include <IRLib_P11_RCMM.h>
// #include <IRLibCombo.h> // After all protocols, include this
// // All of the above automatically creates a universal decoder
// // class called "IRdecode" containing only the protocols you want.
// // Now declare an instance of that decoder.
// IRdecode myDecoder;

// // Include a receiver either this or IRLibRecvPCI or IRLibRecvLoop
// #include <IRLibRecv.h>
// IRrecv myReceiver(11); //pin number for the receiver

// void setup()
// {
//     Serial.begin(9600);
//     delay(2000);
//     while (!Serial);         //delay for Leonardo
//     myReceiver.enableIRIn(); // Start the receiver
//     Serial.println(F("Ready to receive IR signals"));
// }
// void loop()
// {
//     //Continue looping until you get a complete signal received
//     if (myReceiver.getResults())
//     {
//         myDecoder.decode();          //Decode it
//         myDecoder.dumpResults(true); //Now print results. Use false for less detail
//         myReceiver.enableIRIn();     //Restart receiver
//     }
// }