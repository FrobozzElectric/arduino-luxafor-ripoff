const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

int incoming_byte;

void setup()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    Serial.begin(9600);
    Serial.setTimeout(50);
}


void loop()
{
    while (Serial.available() < 3);

    int incoming_byte = Serial.parseInt();
    show_rgb(incoming_byte);
}

void show_rgb(int color)
{
    int red_intensity;
    int green_intensity;
    int blue_intensity;

    // 000 is off 
    // 255 is pure green
    // 511 is pure blue
    // 767 is pure red

    if (color == 000)
    {
        red_intensity = 0;
        green_intensity = 0;
        blue_intensity = 0;
    }
    else if (color <= 255)
    {
        red_intensity = 255 - color;
        green_intensity = color;
        blue_intensity = 0;
    }
    else if (color <= 511)
    {
        red_intensity = 0;
        green_intensity = 255 - (color - 256);
        blue_intensity = (color - 256);
    }
    else
    {
        red_intensity = (color - 512);
        green_intensity = 0;
        blue_intensity = 255 - (color - 512);
    }

    analogWrite(RED_PIN, red_intensity);
    analogWrite(GREEN_PIN, green_intensity);
    analogWrite(BLUE_PIN, blue_intensity);
}
