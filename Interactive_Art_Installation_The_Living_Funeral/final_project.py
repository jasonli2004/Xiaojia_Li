import tkinter as tk
import serial
import pygame
import requests
from time import sleep
from tkinter import ttk

#all tkinter related code was adapted from the following tutorial: https://www.geeksforgeeks.org/python-tkinter-tutorial/
ser = None
pygame.mixer.init()
first_sound = pygame.mixer.Sound('audio_cs/rain_short.mp3')
second_sound = pygame.mixer.Sound('audio_cs/music_pt2.mp3')
channel0 = pygame.mixer.Channel(0)
channel0.set_volume(0.8)
channel1 = pygame.mixer.Channel(1)
channel1.set_volume(1.3)
channel0.play(first_sound)

def get_pronoun():
    global pronoun, p1, p2, p3
    if pronoun == 1:
        p1 = "he"
        p2 = "his"
        p3 = "him"
    if pronoun == 2:
        p1 = "she"
        p2 = "her"
        p3 = "her"
    if pronoun == 3:
        p1 = "they"
        p2 = "their"
        p3 = "them"
     

def submit_intro():
    global name, pronoun, name_block, pronoun_var
    name = name_block.get()
    pronoun = pronoun_var.get()
    get_pronoun()
    intro.after(1, intro.destroy())

def intro_window():
    global intro, name_block, pronoun_var
    intro.title("Name and Pronoun")
    window_width = 400
    window_height = 200
    screen_width = intro.winfo_screenwidth()
    screen_height = intro.winfo_screenheight()
    center_x = int(screen_width/2 - window_width / 2)
    center_y = int(screen_height/2 - window_height / 2)
    intro.geometry(f"{window_width}x{window_height}+{center_x}+{center_y}")
    tk.Label(intro, text="Type in your preferred first name:").pack()
    name_block = tk.Entry(intro)
    name_block.pack()
    pronoun_var = tk.IntVar()
    tk.Radiobutton(intro, text="He/Him", variable=pronoun_var, value=1).pack()
    tk.Radiobutton(intro, text="She/Her", variable=pronoun_var, value=2).pack()
    tk.Radiobutton(intro, text="They/Them", variable=pronoun_var, value=3).pack()
    submit_button = tk.Button(intro, text="submit", command=submit_intro)
    submit_button.pack()

def submit_three():
    global wish1, wish2, wish3, wish1_entry, wish2_entry, wish3_entry, three_wish
    wish1 = wish1_entry.get()
    wish2 = wish2_entry.get()
    wish3 = wish3_entry.get()
    three_wish.after(1, three_wish.destroy())

def set_up_three_wish_window():
    global three_wish, wish1_entry, wish2_entry, wish3_entry
    three_wish.title("Questions")
    window_width = 600
    window_height = 400
    screen_width = three_wish.winfo_screenwidth()
    screen_height = three_wish.winfo_screenheight()
    center_x = int(screen_width/2 - window_width/2)
    center_y = int(screen_height/2 - window_height/2)
    three_wish.geometry(f"{window_width}x{window_height}+{center_x}+{center_y}")

    tk.Label(three_wish, text="Enter your first important thing you want/are pursuing:").pack()
    wish1_entry = tk.Entry(three_wish, width=50)
    wish1_entry.pack()

    tk.Label(three_wish, text="Enter your second important thing you want/are pursuing:").pack()
    wish2_entry = tk.Entry(three_wish, width=50)
    wish2_entry.pack()

    tk.Label(three_wish, text="Enter your third important thing you want/are pursuing:").pack()
    wish3_entry = tk.Entry(three_wish, width=50)
    wish3_entry.pack()
    submit_button = tk.Button(three_wish, text="submit", command=submit_three)
    submit_button.pack()

def submit_choice():
    global life_choice, choice_var
    life_choice = choice_var.get()
    choice_window.after(1, choice_window.destroy())

def setup_choice_window():
    global choice_window, choice_var
    choice_window.title("Life Question")
    window_width = 600
    window_height = 300
    screen_width = choice_window.winfo_screenwidth()
    screen_height = choice_window.winfo_screenheight()
    center_x = int(screen_width/2 - window_width / 2)
    center_y = int(screen_height/2 - window_height / 2)
    choice_window.geometry(f"{window_width}x{window_height}+{center_x}+{center_y}")
    tk.Label(choice_window, text="Would you rather die tomorrow or live forever?").pack()
    choice_var = tk.StringVar()
    tk.Radiobutton(choice_window, text="Die Tomorrow", variable=choice_var, value=1).pack()
    tk.Radiobutton(choice_window, text="Live Forever", variable=choice_var, value=2).pack()
    submit_button = tk.Button(choice_window, text="submit", command=submit_choice)
    submit_button.pack()

def submit_last():
    global thing1, thing2, thing3, thing1_entry, thing2_entry, thing3_entry
    thing1 = thing1_entry.get()
    thing2 = thing2_entry.get()
    thing3 = thing3_entry.get()
    last_24.after(1, last_24.destroy())

def setup_last_24_window():
    global last_24, thing1_entry, thing2_entry, thing3_entry
    last_24.title("in you ast 24 Hours")
    window_width = 600
    window_height = 400
    screen_width = last_24.winfo_screenwidth()
    screen_height = last_24.winfo_screenheight()
    center_x = int(screen_width/2 - window_width / 2)
    center_y = int(screen_height/2 - window_height / 2)
    last_24.geometry(f"{window_width}x{window_height}+{center_x}+{center_y}")

    tk.Label(last_24, text="In the last 24 hours, I will").pack()
    thing1_entry = tk.Entry(last_24, width=50)
    thing1_entry.pack()
    tk.Label(last_24, text="In the last 24 hours, I will").pack()
    thing2_entry = tk.Entry(last_24, width=50)
    thing2_entry.pack()
    tk.Label(last_24, text="In the last 24 hours, I will").pack()
    thing3_entry = tk.Entry(last_24, width=50)
    thing3_entry.pack()
    submit_button = tk.Button(last_24, text="Submit", command=submit_last)
    submit_button.pack()

def submit_survey():
    global survey_dic
    survey_dic = {
        "funeral_date": funeral_date_var.get(),
        "weather": weather_var.get(),
        "age": age_entry.get(),
        "fav_num": fav_number_entry.get(),
        "quote": quote_entry.get(),
        "natural": nature_element_var.get(),
        "representation": object_entry.get(),
        "hobby": hobby_entry.get(),
        "happyness": content_var.get()
    }
    survey_window.after(1, survey_window.destroy())

def set_up_survey_window():
    global funeral_date_var, weather_var, age_entry, fav_number_entry, quote_entry
    global nature_element_var, object_entry, hobby_entry, content_var, survey_window

    survey_window = tk.Tk()
    survey_window.title("Funeral Info")
    survey_window.geometry("500x700")  
    tk.Label(survey_window, text="funeral_date (MM/DD/YYYY):").pack()
    funeral_date_var = tk.StringVar()
    tk.Entry(survey_window, textvariable=funeral_date_var).pack()

    tk.Label(survey_window, text="your preferred weather to host funeral:").pack()
    weather_options = ["Rainy", "Sunny", "Chilly", "Foggy", "Snowy", "Stormy"]
    weather_var = tk.StringVar()
    weather_var.set(weather_options[0])
    ttk.Combobox(survey_window, textvariable=weather_var, values=weather_options).pack()

    tk.Label(survey_window, text="Your Current Age:").pack()
    age_entry = tk.Entry(survey_window)
    age_entry.pack()

    tk.Label(survey_window, text="Favorite Number:").pack()
    fav_number_entry = tk.Entry(survey_window)
    fav_number_entry.pack()

    tk.Label(survey_window, text="A Quote to deliver on your funeral:").pack()
    quote_entry = tk.Entry(survey_window)
    quote_entry.pack()

    tk.Label(survey_window, text="Choose One - Wind, River, Mountain:").pack()
    nature_elements = ["Wind", "River", "Mountain"]
    nature_element_var = tk.StringVar()
    nature_element_var.set(nature_elements[0])
    ttk.Combobox(survey_window, textvariable=nature_element_var, values=nature_elements).pack()

    tk.Label(survey_window, text="An Object That Represents You:").pack()
    object_entry = tk.Entry(survey_window)
    object_entry.pack()

    tk.Label(survey_window, text="One of My hobby is That I Love to:").pack()
    hobby_entry = tk.Entry(survey_window)
    hobby_entry.pack()

    tk.Label(survey_window, text="Are You Content with Your Life Now?").pack()
    content_options = ["Yes", "No"]
    content_var = tk.StringVar()
    content_var.set(content_options[0])
    ttk.Combobox(survey_window, textvariable=content_var, values=content_options).pack()

    submit_button = tk.Button(survey_window, text="Submit", command=submit_survey)
    submit_button.pack()

    survey_window.mainloop()


# from https://elevenlabs.io/ API documentation
def get_audio(text_prompt, file_name):
    CHUNK_SIZE = 1024
    url = "https://api.elevenlabs.io/v1/text-to-speech/TxGEqnHWrfWFTfGW9XjX"

    headers = {
        "Accept": "audio/mpeg",
        "Content-Type": "application/json",
        "xi-api-key": "b2e0da6cf28cfdbc574fce8b15370078"
    }

    data = {
        "text": text_prompt,
        "model_id": "eleven_monolingual_v1",
        "voice_settings": {
            "stability": 0.5,
            "similarity_boost": 0.5,
            "style": 0.9
        }
    }

    response = requests.post(url, json=data, headers=headers)

    if response.status_code == 200:
        # print("Audio retrieval successful")
        with open(file_name, 'wb') as f:
            for chunk in response.iter_content(chunk_size=CHUNK_SIZE):
                if chunk:
                    f.write(chunk)
        return file_name
    else:
        # print(f"Failed to retrieve audio file: Status code {response.status_code}")
        return None


# from https://elevenlabs.io/ API documentation
def get_audio_person(text_prompt, file_name):
    CHUNK_SIZE = 1024
    url = "https://api.elevenlabs.io/v1/text-to-speech/TxGEqnHWrfWFTfGW9XjX"

    headers = {
        "Accept": "audio/mpeg",
        "Content-Type": "application/json",
        "xi-api-key": "b2e0da6cf28cfdbc574fce8b15370078"
    }

    data = {
        "text": text_prompt,
        "model_id": "eleven_monolingual_v1",
        "voice_settings": {
            "stability": 0.5,
            "similarity_boost": 0.5,
            "style": 0.9
        }
    }

    response = requests.post(url, json=data, headers=headers)

    if response.status_code == 200:
        # print("Audio retrieval successful")
        with open(file_name, 'wb') as f:
            for chunk in response.iter_content(chunk_size=CHUNK_SIZE):
                if chunk:
                    f.write(chunk)
        return file_name
    else:
        # print(f"Failed to retrieve audio file: Status code {response.status_code}")
        return None

def wait_button():
    global ser
    if ser is None:
        ser = serial.Serial('COM3', 9600, timeout=1) 
    while True:
        potValues = ser.read(size=1)
        if potValues and potValues[0] == 49:  
            break
        sleep(0.1) 

def evoke_button():
    global ser
    ser.close()
    newser = serial.Serial('COM3', 9600, timeout=1)  # Set a timeout for the read
    while True:
        potValues = newser.read(size=1)
        break

def finish_play():
    global channel1
    while channel1.get_busy():
        pygame.time.delay(100)

def play_intro():
    global intro, channel1
    intro = pygame.mixer.Sound('audio_cs/intro.mp3')
    channel1.play(intro)
    finish_play()

def play_three():
    global name
    text = "Hi, " + name + ", it’s a pleasure to meet you. To know you a little better, I want you to think about your whole life till this very moment, what do you consider to be the three most important things in your life.  Go ahead and enter your answers. "
    get_audio(text, "three.mp3")
    three = pygame.mixer.Sound("three.mp3")
    channel1.play(three)
    finish_play()

def play_choice():
    global channel1
    choice = pygame.mixer.Sound('audio_cs/choice.mp3')
    channel1.play(choice)
    finish_play()

def play_die():
    global name
    text = "You chose to die tomorrow. Although this is quite unlikely, but You never know which will come first: your tomorrow, or your end..... We all gonna die. But, for you," + name +", you are going to die 'tomorrow'. Yes <break time=\"0.6s\" /> TOMORROW <break time=\"0.7s\" />. Now you have 24 hours before you die tomorrow."
    get_audio(text, "die.mp3")
    die = pygame.mixer.Sound("die.mp3")
    channel1.play(die)
    finish_play()

def play_live():
    global name
    text = "While living forever might seem to be desirable, the fact is that you can’t live forever, at least it’s not possible with the technology we have now. So <break time=\"0.5s\" /> death is inevitable, and you are going to die. Yes, <break time=\"1.0s\" /> And " + name+ ", you are going to die 'Tomorrow'. Cause of death:  unknown.<break time=\"1.0s\" /> Now you have 24 hours before you die tomorrow. "
    get_audio(text, "live.mp3")
    live = pygame.mixer.Sound("live.mp3")
    channel1.play(live)
    finish_play()

def play_last():
    global channel1, name
    last = pygame.mixer.Sound('audio_cs/last.mp3')
    channel1.play(last)
    finish_play()
    text = "Now," +name+ ", take some time to think about it and then enter the three things you'd want to do in your last 24 hours of life."
    get_audio(text, "last_pt2.mp3")
    last_pt2 = pygame.mixer.Sound('last_pt2.mp3')
    channel1.play(last_pt2)
    finish_play()

def play_go():
    global channel1
    go = pygame.mixer.Sound('audio_cs/go.mp3')
    channel1.play(go)

def play_passed():
    global channel1
    text = name + " passed away on November 19th, 2023. <break time=\"1.3s\" /> Now… the first stage of your death is completed."
    get_audio(text, "passed.mp3")
    passed = pygame.mixer.Sound('passed.mp3')
    channel1.play(passed)
    finish_play()

def play_prep():
    global channel1
    prep = pygame.mixer.Sound('audio_cs/prep.mp3')
    channel1.play(prep)

def play_youtube():
    global channel1
    youtube = pygame.mixer.Sound('audio_cs/youtube.mp3')
    channel1.play(youtube)

def play_survey():
    global channel1
    survey = pygame.mixer.Sound('audio_cs/survey.mp3')
    channel1.play(survey)
    finish_play()

def play_script():
    global channel1
    text = "Ladies and Gentlemen, on this " + survey_dic["weather"] + " morning of " + survey_dic["funeral_date"] + ", we gathered here to remember and celebrate the life of " +name+ ", who touched the lives of so many. We come together in grief, acknowledging our human loss, but also in gratitude for the life that " + p1 + " lived. "
    get_audio_person(text, "passed.mp3")
    passed = pygame.mixer.Sound('passed.mp3')
    channel1.play(passed)
    finish_play()

def play_7way():
    global channel1, fav_number_entry
    num = int(survey_dic["fav_num"])%6 
    if (num == 1):
        option1 = pygame.mixer.Sound('audio_cs/option1.mp3')
        channel1.play(option1)
    elif (num == 2):
        option2 = pygame.mixer.Sound('audio_cs/option2.mp3')
        channel1.play(option2)
    elif (num == 3):
        text = "On the 19th of November, 2023, the wind that have brought "+name+" to the world, brought"+ p3 +"away. "+p1+" escaped the earth successfully, free from the mortal tether."
        get_audio_person(text, "option3.mp3")
        option3 = pygame.mixer.Sound('option3.mp3')
        channel1.play(option3)
    elif (num == 4):
        text = "On the 19th of November, 2023, our dear friend" +name+ ", was at the helm of "+p2+" cherished car, the hum of the engine a familiar comfort. Tragedy struck in an instant of unforeseen bravery—"+p1+" departed from this life in a selfless act, veering away to protect a life just beginning, as a baby emerged onto the roadway. "+p2+" final act, one of instinctive compassion, leaves us in a wake of heartbreak and awe at the profound depth of "+ p2 +" character."
        get_audio_person(text, "option4.mp3")
        option4 = pygame.mixer.Sound('option4.mp3')
        channel1.play(option4)        
    elif (num == 5):
        text = "On the 19th of November, 2023, our dear friend "+name+", while descending the familiar staircase, met with an untimely fate. "+p2+" foot faltered, and "+p2+" journey ended in sudden stillness, leaving us to ponder the fragility of life with each step we take."
        get_audio_person(text, "option5.mp3")
        option5 = pygame.mixer.Sound('option5.mp3')
        channel1.play(option5)  
    else: 
        text = "On the 19th of November, 2023, our dear friend " +name+", while embracing the azure embrace of the ocean, succumbed to its enigmatic depths. "+ p2 +" spirit, now unbound, swims with the currents of eternity, leaving us to navigate the tides of grief and memory in [pronoun] wake."
        get_audio_person(text, "option6.mp3")
        option6 = pygame.mixer.Sound('option6.mp3')
        channel1.play(option6)  

    finish_play()
        
def play_quote():
    global channel1
    text = name + " asked me to share a quote with you on this very special moment: the quote goes as this : " + survey_dic["quote"]
    get_audio_person(text, "quote.mp3")
    quote = pygame.mixer.Sound('quote.mp3')
    channel1.play(quote)
    finish_play()

def play_object():
    global channel1
    if (survey_dic["natural"] == "Wind"):
        text = "If you think about "+name+ "in the future, and decide to wander, know that "+p1+ "will be nestled within nature's embrace, playfully peeking from the rustling leaves or dancing upon the sunlit streams."
        get_audio_person(text, "wind.mp3")
        wind = pygame.mixer.Sound('wind.mp3')
        channel1.play(wind)
    else:
        text = "Dear friends and families, if you ever miss "+name+", just seek out a "+ survey_dic["representation"]+". No matter when and where, "+p1+" will always be there for you, in the gentle echo of your laughter and the soft shadows of your memories."
        get_audio_person(text, "object.mp3")
        object = pygame.mixer.Sound('object.mp3')
        channel1.play(object)
    finish_play()

def play_hobby():
    global channel1
    text = "While "+name+" walked among us, "+p2+" favorite pastime was "+survey_dic["hobby"]+", a pursuit that brought joy to "+p2+" days and light to those around "+p3
    get_audio_person(text, "hobby.mp3")
    hobby = pygame.mixer.Sound('hobby.mp3')
    channel1.play(hobby)
    finish_play()

def play_content():
    global channel1
    result = survey_dic["happyness"]  
    if (result == "Yes"):
        text = "Although "+p1+" never becomes the most famous or the wealthiest, "+p1+" pursued "+p2+" goals : "+wish1+"," +wish2+","+wish3+ ", with quiet dedication. The extent of "+p2+" progress on these paths may remain unknown to us, yet "+p1+" found richness in the simple pleasures of life. Content with "+p2+" lot, "+p1+" heartily embraced the joys of living, delighting in gastronomy and merriment, exploring the splendor of nature, and fostering deep bonds with a circle of steadfast and loyal friends."
        get_audio(text,'happy.mp3')
        happy = pygame.mixer.Sound('happy.mp3')
        channel1.play(happy)
    else: 
        text = "A lot of people are always so busy…. busy drinking, busy making money, and busy having emotional crises. A lot of time passed in this busy way. However, "+p1+" carried within "+p3+" a restless yearning for "+p2+" goals of "+wish1+"," +wish2+","+wish3+ ". The dreams "+p1+"chased, with fervor and silent resolve, remain unfinished symphonies, their melodies hanging in the balance of what could have been. Despite this, "+p1+" never ceased to engage with the world ardently, seeking joy in the vibrant tapestry of life, from the simplest of pleasures to the grandest of adventures, and forging bonds with those few who truly understood the tempest of "+p2+" spirit."
        get_audio(text,'sad.mp3')
        sad = pygame.mixer.Sound('sad.mp3')
        channel1.play(sad)
    finish_play()

def play_conclude():
    global channel1
    text = "As we draw this gathering to a close, let us hold in our hearts the essence of "+name+", who now takes a new journey beyond our sight. May we find solace in the love "+p1+" shared, the paths "+p1+" walked alongside us, and the indelible mark "+p1+" left on our lives. In the tapestry of memory, "+p1+" remains an eternal thread, vibrant and strong. As we walk forth from this place, let each of us carry a spark of "+p2+" spirit, igniting it in acts of kindness, in laughter shared, and in moments of quiet reflection. "+p2+" story, though paused in the telling, continues within us all."
    get_audio_person(text, "conclude.mp3")
    conclude = pygame.mixer.Sound('conclude.mp3')
    channel1.play(conclude)
    finish_play()

def play_lastword():
    global channel1
    lastword = pygame.mixer.Sound('audio_cs/lastword.mp3')
    channel1.play(lastword)
    finish_play()

def play_complete():
    global channel1
    complete = pygame.mixer.Sound('audio_cs/complete.mp3')
    channel1.play(complete)
    finish_play()

def play_thank():
    global channel1
    thank = pygame.mixer.Sound('audio_cs/thank.mp3')
    channel1.play(thank)
    finish_play()

def play_baby():
    global channel1
    baby_cry = pygame.mixer.Sound('audio_cs/baby_cry.mp3')
    channel1.play(baby_cry)
    finish_play()

play_intro()

intro = tk.Tk()
intro_window()
intro.maxsize()
intro.mainloop()

play_three()

three_wish = tk.Tk()
set_up_three_wish_window()
three_wish.mainloop()

play_choice()

choice_window = tk.Tk()
setup_choice_window()
choice_window.mainloop()

if life_choice == 1:
    play_die()
else:
    play_live()

play_last()

last_24 = tk.Tk()
setup_last_24_window()
last_24.mainloop()

play_go()

wait_button()

play_passed()

play_prep()

wait_button()

play_survey()

set_up_survey_window()
channel0.stop()
play_youtube()


wait_button()

play_script()
play_7way()
play_quote()
play_object()
play_hobby()
play_content()

play_conclude()
channel0.play(second_sound)

play_lastword()

wait_button()



play_complete()

evoke_button()

play_baby()

play_thank()

while True:
    pass