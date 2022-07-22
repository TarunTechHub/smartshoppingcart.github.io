// Options the user could type in
const prompts = [
  ["hi", "hey", "hello", "good morning", "good afternoon"],//1
  ["how are you", "how is life", "how are things"],//2
  ["what are you doing", "what is going on", "what is up"],//3
  ["how old are you"],//4
  ["who are you", "are you human", "are you bot", "are you human or bot"],//5
  ["who created you", "who made you"],//6
  [
    "your name please",
    "your name",
    "may i know your name",
    "what is your name",
    "what call yourself"
  ],//7
  ["i love you"],//8
  ["happy", "good", "fun", "wonderful", "fantastic", "cool"],//9
  ["bad", "bored", "tired"],//10
  ["help me", "tell me story", "tell me joke"],//11
  ["ah", "yes", "ok", "okay", "nice"],//12
  ["bye", "good bye", "goodbye", "see you later"],//13
  ["what should i eat today"],//14
  ["bro"],//15
  ["what", "why", "how", "where", "when"],//16
  ["no","not sure","maybe","no thanks"],//17
  [""],//18
  ["haha","ha","lol","hehe","funny","joke"],//19
  ["I'm Sanjana Tell About Me"]
]

// Possible responses, in corresponding order

const replies = [
  ["Hello!", "Hi!", "Hey!", "Hi there!","Howdy"],//1
  [
    "Fine... how are you?",
    "Pretty well, how are you?",
    "Fantastic, how are you?"
  ],//2
  [
    "Nothing much",
    "About to go to sleep",
    "Can you guess?",
    "I don't know actually"
  ],//3
  ["I am infinite"],//4
  ["I am just a bot", "I am a bot. What are you?"],//5
  ["The one true God, JavaScript"],//6
  ["I am nameless", "I don't have a name"],//7
  ["I love you too", "Me too"],//8
  ["Have you ever felt bad?", "Glad to hear it"],//9
  ["Why?", "Why? You shouldn't!", "Try watching TV"],//10
  ["What about?", "Once upon a time..."],//11
  ["Tell me a story", "Tell me a joke", "Tell me about yourself"],//12
  ["Bye", "Goodbye", "See you later"],//13
  ["Sushi", "Pizza"],//14
  ["Bro!"],//15
  ["Great question"],//16
  ["That's ok","I understand","What do you want to talk about?"],//17
  ["Please say something :("],//18
  ["Haha!","Good one!"],//19
  ["your are gem and most favourite person in my life"]
]

// Random for any other user input

const alternative = [
  "Same",
  "Go on...",
  "Bro...",
  "Try again",
  "I'm listening...",
  "I don't understand :/"
]

// Whatever else you want :)

const coronavirus = ["Please stay home", "Wear a mask", "Fortunately, I don't have COVID", "These are uncertain times"]