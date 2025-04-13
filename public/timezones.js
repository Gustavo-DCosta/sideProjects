document.getElementById("searchBtn").addEventListener("click", function () {
    const fromCity = document.getElementById("fromCity").value.trim();
    const toCity = document.getElementById("toCity").value.trim();
  
    if (!fromCity || !toCity) {
      alert("Please enter both cities!");
      return;
    }
  
    fetch("/api/timezones", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify({
      from: fromCity,
      to: toCity
    })
  })
    .then(res => res.json())
    .then(data => {
      document.getElementById("result").innerText =
        `Searching from: ${data.from} ⏱️\nTo: ${data.to} ⏱️`;
    })
    .catch(err => console.error("Error:", err));
});
  