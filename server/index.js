const express = require('express');
const path = require('path');

const app = express();
const PORT = 3000;

app.use(express.json());
// Serve everything from public/
app.use(express.static(path.join(__dirname, '..', 'public')));
app.use('/photos', express.static(path.join(__dirname, '..', 'photos')));

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "..", "public", "home.html"));
  // Remove the res.send() - 
})

app.get("/about", (req, res) => {
  res.sendFile(path.join(__dirname, "..", "public", "about.html"));
  // Remove the res.send()
})

app.get("/timzeones", (req, res) => {
  res.sendFile(path.join(__dirname, "..", "public", "timezones.html"));
  // Remove the res.send()
})

app.post("/api/timezones", (req, res) => {
  const from = req.body.from;
  const to = req.body.to;

  console.log("From:", from);
  console.log("To:", to);


  res.json({ from, to });
});

app.listen(PORT, () => {
  console.log(`✨ SamePages server running at http://localhost:${PORT}`);
});