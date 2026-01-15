# 🤖 AI-Like Smart Chatbot in C

A simple, interactive **AI-like chatbot** built entirely using the **C programming language**.  
The chatbot can talk, learn new answers, and store them permanently in a text-based memory.

---

## 📌 Project Overview

This chatbot:
- Greets users based on the current time  
- Accepts text input  
- Searches for answers in a memory file (`knowledge.txt`)  
- Learns new answers when it encounters unknown questions  
- Saves learned answers permanently  
- Responds with random friendly replies for a natural chat feel  

Ideal mini-project for **1st-year C programming students**, but looks **unique and impressive**.

---

## 🚀 Features

### ✔ Time-Based Greeting  
Displays:
- **Good Morning**  
- **Good Afternoon**  
- **Good Evening**

### ✔ Learning Capability  
If the chatbot doesn't know an answer, it asks:

```
I don't know that yet. Can you teach me?
```

After the user teaches a response, it is saved to the memory file.

### ✔ Permanent Memory  
Learns and saves new Q&A pairs in:

```
knowledge.txt
```

### ✔ Clean Input Handling  
- Converts all text to lowercase  
- Removes newline characters  
- Prevents input formatting issues  

### ✔ Random Friendly Responses  
After each reply, bot reacts with friendly messages like:

```
That's interesting!
Tell me more...
Wow, really?
```

---

## 🗂 Files Included

| File Name                  | Purpose                                |
|---------------------------|-----------------------------------------|
| `chatbot.c`               | Main chatbot source code                |
| `knowledge.txt`           | Stores learned question–answer pairs    |
| `SmartChatbotProject.zip` | Full project folder (optional upload)   |

---

## 🛠 How to Compile and Run

### **Step 1: Compile**
```bash
gcc chatbot.c -o chatbot.exe
```

### **Step 2: Run**  
PowerShell:
```bash
.\chatbot.exe
```

CMD:
```bash
chatbot.exe
```

---

## 🧠 How Learning Works

1. User asks a question  
2. Chatbot checks memory file  
3. If answer is found → chatbot replies  
4. If not → chatbot asks for the answer  
5. Chatbot stores it permanently

**Example**

```
You: what is ai
Bot: I don't know that yet. Can you teach me? (yes/no)
You: yes
Teach me the answer: AI means Artificial Intelligence.
Bot: Got it! I will remember this.
```

Stored in memory as:
```
what is ai=AI means Artificial Intelligence.
```

---

## 📌 Project Output Example

```
Good Evening!
I am your C Chatbot! Type 'exit' to quit.

You: hi
Bot: hello!
That's interesting!

You: what is ai
Bot: I don't know that yet. Can you teach me? (yes/no)
```

---

## ✨ Future Enhancements (Optional)

- Add keyword-based matching  
- Add synonyms (hi, hello, hey → same meaning)  
- Add delete/edit answer options  
- GUI version using C++ or Python  
- Export learning memory  

---

## 👩‍💻 Author  
**Shruhti Somani**

