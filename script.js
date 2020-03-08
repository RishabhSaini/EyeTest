function record(){
    var recognition = new webkitSpeechRecognition();
    recognition.lang = "en-IN";
    
    recognition.onresult = function(event){
        console.log(event);
        document.getElementById('good').innerText = event.results[0][0].transcript;
        var trans = event.results[0][0].transcript.toUpperCase();
        if( trans.indexOf("SHE") != -1){
            document.getElementById('hi').innerText = "20/100 Vision"
        }
        if( trans.indexOf("WALKED ACROSS") != -1){
            document.getElementById('hi').innerText = "20/70 Vision"
        }
        if( trans.indexOf("THE STREET TO BRING") != -1){
            document.getElementById('hi').innerText = "20/50 Vision"
        }
        if( trans.indexOf("HER BROTHER BACK HOME") != -1){
            document.getElementById('hi').innerText = "20/40 Vision"
        }
        if( trans.indexOf("SHOW THEM HOW TO USE THIS") != -1){
            document.getElementById('hi').innerText = "20/30 Vision"
        }
        if( trans.indexOf("NEW COMPUTER FOR THEIR WORK TODAY") != -1){
            document.getElementById('hi').innerText = "20/20 Vision"
        }
    }
    
    recognition.start();
}