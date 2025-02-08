# Lesson 0x03 Exercises

## Exercise 0x0
Build a program that can calculate the speeding penalties on Danish controlled-access highways and limited-access.

Requirements
- Given a speed measurement speed limit and a vehicle type, calculate the base penalty using Table 1
- If the speed measurement are 140 km/h or above, calculate an additional high speed penalty using Table 2
- To increase productivity for the personel handling the fines, the program should continue prompting the user for data (speed limit, speed measurement and vehicle type) until terminated
- The speed limits input should be restricted to 100, 110, 120, or 130 km/h and print out a message to the user if they provide an invalid value

The size of the penalty depends on the type of the vehicle the driver is driving. For what we would consider a normal car, it depends on which type of road you're driving on, while heavy vehicles and cars with trailers all are fined the same amount. 
- **Takst 1** — Cars, motorcycles and busses not above 3.500 kg and construction vehicles outside controlled-access highways and limited-access roads with a speed limit below 100 km/h.
- **Takst 2** — Cars, motercycles and busses not above 3.500 kg on limited-access roads with a speed limit of 100 km/t and controlled-access highways with a speed limit on 100 km/h and above
- **Takst 3** — Heavy vehicles (busses, trucks, semi-trucks) above 3.500 kg and cars with trailers not above 3.500 kg.

|Procent|100 km/t.|110 km/t.|120 km/t.|130 km/t.|Takst 2|Takst 3|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|u/20|101-119|111-131|121-143|131-155|1.200 kr.|1.800 kr.|
|20-29|120-129|132-142|144-155|156-168|1.800 kr.|1.800 kr.|
|30-39|130-139|143-153|156-167|169-181|2.400 kr.|2.400 kr.|
|40-49|140-149|154-164|168-179|182-194|3.000 kr.|3.000 kr.|
|50-59|150-159|165-175|180-191|195-207*|3.600 kr.|3.600 kr.|
|60-69|160-169|176-186|192-203*|208-220*|4.200 kr.|4.200 kr.|
|70-79|170-179|187-197|204-215*|221-233*|5.400 kr.|5.400 kr.|
|80-89|180-189|198-208|216-227*|234 -246*|6.000 kr.|6.000 kr.|
|90-99|190-199|209-219|228-239*|247-259*|7.800 kr.|7.800 kr.|
|100-|200-*|220-*|240-*|260-*|9.000 kr.|9.000 kr.|

<small>Table1 — On limited-access roads with a speed limit of 100 km/h and controlled-access highways with a speed limit on 100 km/h and above[^1]</small>

In addition to the penalty defined in Table 1, an additional penalty will be issued, if the measured as described in the Table 2 below.

|km/t.|Tillæg|
|:-:|:-:|
|140-149|1.200 kr.|
|150-159|1.800 kr.|
|160-169|2.400 kr.|
|170-179|3.000 kr.|
|180-189|3.600 kr.|
|190-199|4.200 kr.|
|200-209|4.800 kr.|
|210-219|5.400 kr.|
|220-229|6.000 kr.|
|osv.|osv.|

<small>Table 2 — Addition high speed penalty for all roads.[^1]</small>

A short recap of the The Seven Steps
- Getting started
  - Do you have the information to get started?
  - Start taking contemporaneous notes while working a single instance of the problem and make sure you cover all constraints (e.g. given a speed of 142 km/h in a zone with a 120 km/h speed limit)
  - Use pseudo code to describe your algorithm
- Generalize and test
  - See if you can categorize some of the steps in your solution from Exercise 0x01. Are there you doing some calculations, that could be generalized in put into functions (check lecture 1 to get a refresher on the syntax)?
  - Try with a few different input values and see if the algorithm still holds up after being generalized.
- Let's cooooode!
  - Now it's time to get going with some code! Fire up your IDE (probably Visual Studio, but I don't care!)
  - Create a new solution and start typing. Don't forget to run your code from time to time, it's a lot easier to make progress, if we don't have to deal with a lot of bugs at the same time
  - Use your pseudo code as a reference in the translation to code
- Test and debug
  - Whenever you have done changes to your done, that you consider to be working as intended (e.g. a `while` loop prompting for user input, a function that calculates the violation percentage, some code to calculate additional high speed penalties), be sure to run and test that everything still works as expected, if not, it's time to debug the defect before adding more code. 

## Exercise 0x01
Expand the program from Exercise 0x0 to also handle the speeding outside controlled-access highways and limited-access roads with a speed limit below 100 km/h as presented in Table 3.

Requirements
- The requirements in Exercise 0x0 still stands, but some have to be modifed, which ones?
- If the violation is 30 % or above, an additional penalty of 1.200 kr. is issued.

|Procent|30 km/t|40 km/t|45 km/t|50 km/t|60 km/t|70 km/t|80 km/t|90 km/t|Takst 1|Takst 3|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|u/20|31-35|41-47|46-53|51-59|61-71|71-83|81-95|91-107|1.200 kr.|1.800 kr.|
|20-29|36-38|48-51|54-58|60-64|72-77|84-90|96-103|108-116|1.800 kr.|1.800 kr.|
|30-39|39-41|52-55|59-62|65-69|78-83|91-97|104-111|117-125|1.800 kr.|2.400 kr.|
|40-49|42-44|56-59|63-67|70-74|84-89|98-104|112-119|126-134|2.400 kr.|3.000 kr.|
|50-59|45-47|60-63|68-71|75-79|90-95|105-111|120-127|135-143|2.400 kr.|3.600 kr.|
|60-69|48-50|64-67|72-76|80-84|96-101|112-118|128-135|144-152|3.000 kr.|4.200 kr.|
|70-79|51-53|68-71|77-80|85-89|102-107|119-125|136-143|153-161|3.600 kr.|5.400 kr.|
|80-89|54-56|72-75|81-85|90-94|108-113|126-132|144-151|162-170|4.200 kr.|6.000 kr.|
|90-99|57-59|76-79|86-89|95-99|114-119|133-139|152-159|171-179|5.400 kr.|7.800 kr.|
|100-|60-|80-|90-|100-*|120-*|140-*|160-*|180-*|6.000 kr.|9.000 kr.|

<small>Table 3 — Outside controlled-access highways and limited-access roads with a speed limit below 100 km/t[^1]</small>

## Exercise 0x2
Take some time to think about which exercises you've been done in the past in this course. Were there any that caused problems (solved or unsolved)?

Try applying The Seven Steps to one or more of them!

[^1]: https://politi.dk/-/media/mediefiler/landsdaekkende-dokumenter/boeder/boeder-det-er-ikke-gratis-at-overtraede-faerdselsloven.pdf, p. 12