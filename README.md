# Image Processing - Parallel Methods (OpenMP)

## 📌 Descriere
Acest proiect realizează conversia unei imagini color în format PPM în grayscale (nuanțe de gri), folosind:

- o metodă secvențială
- o metodă paralelă cu OpenMP (static scheduling)
- o metodă paralelă cu OpenMP (dynamic scheduling)

Scopul este compararea performanței dintre execuția secvențială și cea paralelă.

---

## ⚙️ Tehnologii utilizate
- C++
- OpenMP
- Visual Studio 2022

---

## 📂 Structura proiectului

- `ImageProcessingSequential.cpp` → varianta secvențială
- `ImageProcessingOpenMP.cpp` → paralelizare cu OpenMP (static)
- `ImageProcessingParallel.cpp` → paralelizare cu OpenMP (dynamic)

---

## ⏱️ Rezultate obținute

Pe o imagine de dimensiune mare:

- Timp secvențial: **~0.023 secunde**
- Timp paralel (static): **~0.011 secunde**
- Timp paralel (dynamic): **~0.069 secunde**

---

## 📊 Concluzii

- Paralelizarea reduce semnificativ timpul de execuție
- Varianta cu **static scheduling** este cea mai eficientă
- Varianta **dynamic** este mai lentă din cauza overhead-ului de distribuire a task-urilor
- Pentru imagini mari, beneficiile paralelizării sunt evidente

---

## ▶️ Rulare

Programul se rulează din Visual Studio folosind:
