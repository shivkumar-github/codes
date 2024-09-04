// const BASE_URL = "https://api.freecurrencyapi.com/v1/status"
const BASE_URL = "https://api.exchangerate-api.com/v4/latest/USD"
const drowpdowns = document.querySelectorAll(".dropdown select");
const btn = document.querySelector("form button");
const fromCurr = document.querySelector(".from select");
const toCurr = document.querySelector(".to select");
const msg = document.querySelector(".msg");

for (let select of drowpdowns) {
    for (currCode in countryList) {
        let newOption = document.createElement("option"); // creates a new option tag which will be added 
        newOption.innerText = currCode;
        newOption.value = currCode;// value assigned to this option tag
        if (select.name === "from" && currCode === "USD") {
            newOption.selected = true;
        }
        else if (select.name === "to" && currCode === "INR") {
            newOption.selected = true;
        }
        select.append(newOption);
    };
    select.addEventListener("change", (evt) => {//evt is the object that contains information about how that event occured
        updateFlag(evt.target);//evt.target is that refers to the element itself that caused that event
    })
};



const updateFlag = (element) => {
    let currCode = element.value;
    let countryCode = countryList[currCode];
    let newSrc = `https://flagsapi.com/${countryCode}/shiny/64.png`;
    let img = element.parentElement.querySelector("img");// not using all because there is only single img tag in each .parentElement
    img.src = newSrc;
};

btn.addEventListener("click", async (evt) => {
    evt.preventDefault();//this prevents default events(like page reloading etc) from occuring when button is clicked (note that when the button of a form is clicked it's default behaviour is to reload the page that's why we need to change it)
    let amount = document.querySelector(".amount input");
    let amtVal = amount.value;
    if (amtVal === "" || amtVal < 1) {
        amtVal = "1";
        amount.value = "1";
    };

    const URL = `${BASE_URL}/${fromCurr.value.toLowerCase()}/${toCurr.value.toLowerCase()}.json`;
    let response = await fetch(URL);
    console.log(response);
    // let data = await response.json();
    // let rate = data[toCurr.value.toLowerCase()];

    // let finalAmount = amtVal * rate;
    // msg.innerText = `${amtVal} ${fromCurr.value} = ${finalAmount} ${toCurr.value}`;
    // console.log(msg.innerText);
});