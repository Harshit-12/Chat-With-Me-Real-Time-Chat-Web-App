const socket = io();
let user;
let textarea = document.querySelector("#textarea");
let messagearea = document.querySelector(".messagearea");
do {
    user= prompt("Please enter your name: ");
} while (!user);
textarea.addEventListener("keyup", (e) => {
    if (e.key=== "Enter"){
        sendmessage(e.target.value);
    }
})

function sendmessage(message) {
    let msg= {
        user: user,
        message: message.trim()
    }

    appendmessage(msg,"out");
    textarea.value=""; 
    scrollToBottom();
    // send to server 
    socket.emit("message",msg);
}

function appendmessage(msg,type) {
    let mainDiv = document.createElement('div')
    let className =type;
    mainDiv.classList.add(className,"message")
    let markup = `<h3 style="color:#8B0000"> ${msg.user}</h3> <p>${msg.message}</p> `

    mainDiv.innerHTML = markup
    messagearea.appendChild(mainDiv)

}

// Recieve Message 

socket.on('message',(msg) => {
    // console.log(msg);
    appendmessage(msg,"inc");
    scrollToBottom();
})

function scrollToBottom()
{
    messagearea.scrollTop =messagearea.scrollHeight;
}