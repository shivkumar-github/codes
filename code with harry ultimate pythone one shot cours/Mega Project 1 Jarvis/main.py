import speech_recognition as sr
import webbrowser
import pyttsx3
import musiclibrary
import os
import requests
    # pip install speechrecognition pyaudio setuptools pyttsx3

recognizer = sr.Recognizer()
engine = pyttsx3.init()
newsapi = "ee8e0e15108841258443c28fcd204d5d"

def speak(text):
        engine.say(text)
        engine.runAndWait()
        
        
def processCommand(c):
        if("open google" in c):
                webbrowser.open("https://www.google.com")
        elif("open facebook" in c):
                webbrowser.open("https://www.facebook.com")
        elif("open linkedin" in c):
                webbrowser.open("https://www.linkedin.com")
        elif("open instagram" in c):
                webbrowser.open("https://www.instagram.com")
        elif("open youtube" in c):
                webbrowser.open("https://www.youtube.com")
        elif(c.startswith("play")):
                song = c.split(" ")[1]
                link = musiclibrary.music[song]
                print(link)
                webbrowser.open(link)
        elif("news" in c):
                response = requests.get(f"https://newsapi.org/v2/top-headlines?country=in&apiKey={newsapi}")                # Check if the request was successful
                if response.status_code == 200:
                        # Parse the JSON response
                        news_data = response.json()
                        
                        # Print the news articles
                        for article in news_data['articles']:
                                speak(f"{article['title']}")
                else:
                        print(f"Failed to fetch news: {response.status_code}")
        else:
                pass
                # let openai handle the request
                
                
# if not opened from another module
if __name__ == "__main__":
        speak("Initializing Jarvis.....")
        while True:
                # Listen for the wake word "Jarvis"
                # obtain the audio from the microphone
                r = sr.Recognizer()
                # recognise speech using Sphinx
                try:
                        with sr.Microphone() as source:
                                print("Listening.....")
                                audio = r.listen(source, timeout = 2, phrase_time_limit = 1) # TOPIC: what is phrase timout limit
                        command = r.recognize_google(audio)
                        command = command.lower()
                        if("stop" in command):
                                break
                        processCommand(command)

                except Exception as e:
                        print("Error; {0}".format(e))
        
