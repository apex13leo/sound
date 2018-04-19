//#define DEBUG		//conditional compiling
//content definitions
#define SAMPLERATE 16000
// header file for processing sound (WAV) file.
//define the wav header
typedef struct{
	char chunkID[4];	//RIFF
	unsigned int chunkSize;	//4 bytes
	char format[4];		//"WAVE"
	char subchunk1ID[4];	//"fmt "
	unsigned int subchunk1Size;
	unsigned short audioFormat;		//16 for PCM
	unsigned short numChannels;		//1 for mono
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char subchunk2ID[4];		// "data"
	unsigned int subchunk2Size;
}WAVheader;

// function prototypes
void displayWAVheader(char filename[]);
void displayBar(char filename[]);
void printID(char id[]);
