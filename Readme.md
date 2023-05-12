# GPS-based Navigation System

This project is designed to implement a GPS-based navigation system using the TM4C123G LaunchPad microcontroller. The system will store the coordinates of the starting point, the destination point, and calculate the total distance that was taken by the user. The output of the system will be displayed using the built-in LED, which will indicate the user's proximity to the destination point.

## Requirements

1. TM4C123G LaunchPad
2. GPS Module
3. Breadboard
4. Jumper wires

## Installation

1. Clone the repository to your local machine.
2. Connect the GPS module to the TM4C123G LaunchPad.
3. Open the project in Energia IDE.
4. Compile and upload the code to the LaunchPad.

## Usage

1. Connect the LaunchPad to a power source.
2. The system will automatically detect the user's current location and store the coordinates as the starting point.
3. Select the destination point by entering the latitude and longitude coordinates.
4. The system will calculate the distance between the starting point and the destination point.
5. The LED will indicate the user's proximity to the destination point based on the following criteria:
    1. Stage 1: The built-in LED will be turned on (green) when the target destination is reached.
    2. Stage 2: The built-in LED will be turned on (yellow) when the target destination is about to be reached < 5 meters.
    3. Stage 3: The built-in LED will be turned on (red) when the target destination is far away by distance > 5 meters.
6. The system will store the coordinates of the end point and the total distance that was taken by the user.
7. The LED will turn off once the user reaches the destination point.

## Trajectory Requirements

1. The total distance between the start and the end point should be > 100 meters.
2. The path from the start point to the end point should form a non-straight line that is similar to the provided baseline path.
3. You have the freedom to select any starting point.
4. The system should calculate the distance between the starting point and the end point.
5. You should ensure that there is no big difference/deviation (error margin should be <= 5%) between your calculated distance and the one shown by Google Maps.

## Authors

- Andrew Gamal Todary 2000042

- Marline mansour mansy 2000977

- Melodia Magdy Mueen 2001399

- Carol Botros Wissa 2000916

- Shady Emad Zaki 2001553

- Andrew Basem Ishak 2000261

- Jan Farag Hanna 2001814 

