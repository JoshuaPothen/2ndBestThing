#include <Arduino.h>

// Array of jokes
const char* jokes[] = {
  "Why don't scientists trust atoms? Because they make up everything!",
  "Why did the scarecrow win an award? He was outstanding in his field!",
  "Why don't eggs tell jokes? They'd crack each other up!",
  "What do you call a fake noodle? An impasta!",
  "Why did the coffee file a police report? It got mugged!",
  "What do you call a bear with no teeth? A gummy bear!",
  "Why don't skeletons fight each other? They don't have the guts!",
  "What do you call a dinosaur that crashes his car? Tyrannosaurus Wrecks!",
  "Why did the math book look so sad? Because it had too many problems!",
  "What do you call a sleeping bull? A bulldozer!",
  "Why don't programmers like nature? It has too many bugs!",
  "What's the best thing about Switzerland? I don't know, but the flag is a big plus!",
  "Why did the bicycle fall over? Because it was two-tired!",
  "What do you call a fish wearing a bowtie? Sofishticated!",
  "Why don't scientists trust stairs? Because they're always up to something!"
};

const int numJokes = sizeof(jokes) / sizeof(jokes[0]);
unsigned long previousMillis = 0;
const long interval = 30000; // 30 seconds in milliseconds

// Function declarations
void displayRandomJoke();
int getRandomJokeIndex();

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Wait for serial port to connect
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // Initialize random seed
  randomSeed(analogRead(0));
  
  Serial.println("=== Arduino Joke Generator ===");
  Serial.println("A new joke every 30 seconds!");
  Serial.println("==============================");
  Serial.println();
  
  // Display the first joke immediately
  displayRandomJoke();
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Check if 30 seconds have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    displayRandomJoke();
  }
  
  // Small delay to prevent overwhelming the processor
  delay(100);
}

// Function to display a random joke
void displayRandomJoke() {
  int jokeIndex = getRandomJokeIndex();
  
  Serial.println("--- New Joke ---");
  Serial.println(jokes[jokeIndex]);
  Serial.println();
  
  // Optional: Print timestamp
  Serial.print("Time: ");
  Serial.print(millis() / 1000);
  Serial.println(" seconds");
  Serial.println("---------------");
  Serial.println();
}

// Function to get a random joke index
int getRandomJokeIndex() {
  return random(0, numJokes);
}
