//Pin for piezo. Change accordingly.
int PIEZOPIN = 5;

// One octave of notes between A4 and A5
int note_A4 = 440;
int note_As4 = 466; int note_Bb4 = note_As4;
int note_B4 = 494;
int note_C5 = 523;
int note_Cs5 = 554; int note_Db5 = note_Cs5;
int note_D5 = 587;
int note_Ds5 = 622; int note_Eb5 = note_Ds5;
int note_E5 = 659;
int note_F5 = 698;
int note_Fs5 = 740; int note_Gb5 = note_Fs5;
int note_G5 = 784;
int note_Gs5 = 830; int note_Ab5 = note_Gs5;

int note_A5 = note_A4 * 2;
int note_As5 = note_As4 * 2; int note_Bb5 = note_As5;
int note_B5 = note_B4 * 2;

int note_rest = -1;

// note lengths defined here
long whole_note = 1600; // change tempo by changing duration of one measure
long half_note = whole_note / 2;
long quarter_note = whole_note / 4;
long eighth_note = whole_note / 8;
long sixteenth_note = whole_note / 16;


// Happy Birthday
long happy_birthday[25][2] = {
  {note_D5, half_note}, 
  {note_D5, half_note},
  {note_E5, whole_note}, 
  {note_D5, whole_note}, 
  {note_G5, whole_note}, 
  {note_F5, whole_note * 2},
  {note_D5, half_note}, 
  {note_D5, half_note},
  {note_E5, whole_note}, 
  {note_D5, whole_note}, 
  {note_A5, whole_note}, 
  {note_G5, whole_note * 2},
  {note_D5, half_note}, 
  {note_D5, half_note},
  {note_Ds5, whole_note}, 
  {note_B4, whole_note},
  {note_G5, whole_note},
  {note_F5, whole_note},
  {note_E5, whole_note},
  {note_C5, half_note},
  {note_C5, half_note},
  {note_B4, whole_note},
  {note_G5, whole_note},
  {note_A5, whole_note},
  {note_G5, whole_note * 2}
};
  
// if you want there to be silence between notes,
//   staccato should be true
bool staccato = true;

//set up the piezo pin (output because we are signaling the piezo element to make a sound)
void setup() {
  pinMode(PIEZOPIN, OUTPUT);
}

//loop: what it will continuously do
void loop() {
  //Loop through the song (note 25 because that's how many notes)
  for(int i=0; i<25; i++){

    //If staccato
    int between = 0;
    if(staccato){
      between = 50;
    }

    // Play tone, or play silence (for rest)
    if (happy_birthday[i][0] == note_rest) {
      noTone(PIEZOPIN);
    }
    else {
      tone(PIEZOPIN, happy_birthday[i][0]);
    }
    delay(happy_birthday[i][1] - between);
    noTone(PIEZOPIN);
    //If staccato
    delay(between);
  }
}
