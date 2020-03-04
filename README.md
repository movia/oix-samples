# 2020 Open Innovation X Challenge Code Samples
Code samples for Movia's case at the 2020 Open Innovation X Challenge, that shows how a IoT device could get data about departures from a specific Stop Point. The code samples serve purely as inspiration - you can use it to get a quick feeling of how you could get data, or not use is at all - it is up to you!

## Prerequisite
We encourage to use [Platform IO IDE](https://platformio.org/install), as it eases the development of IoT and embedded prototypes significantly.

## Code Samples:

### NodeMCU-32 Connection via Wifi
Even though wifi will almost certainly not be available in general at bus stops, and in generel sonsumes a lot of power, this sample shows how you can use a nearby wifi network to get data: It also allows you to focus on the presentation of the data rather than network connectivity, e.g. using your smartphone as an access point.

[Show me the code](/NodeMCU-32-Wifi/src/main.cpp)

## Data Access
You can get departures from a specific stop point (given by its StopPointId) using the following REST service, where the last number indicates the StopPointId, e.g.:
https://movia-oi-x.azurewebsites.net/api/stop/499

Here are a couple of stop points near DTU SkyLAB you can use:
- 471 - Elektrovej (Lundtoftevej), North bound
- 499 - Elektrovej (Lundtoftevej), South bound
- 6026 - Rævehøjvej, DTU (Helsingørmotorvejen), North bound
- 6015 - Rævehøjvej, DTU (Helsingørmotorvejen), South bound  
