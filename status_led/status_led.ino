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

    led_off();
}


void loop()
{
    while (Serial.available() < 3);

    int incoming_byte = Serial.parseInt();
    show_rgb(incoming_byte);

        //switch (incoming_byte) {
        //case 'R':
        //    led_red();
        //    break;
        //case 'G':
        //    led_green();
        //    break;
        //case 'B':
        //    led_blue();
        //    break;
        //case 'O':
        //    led_off();
        //    break;
        //default:
        //    int rgb_value = incoming_byte;
        //    showRGB(rgb_value);
        //    break;
        //}

    //}
}

void led_off()
{
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
}


void led_red()
{
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
}


void led_green()
{
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
}


void led_blue()
{
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
}


void show_rgb(int color)
{
    int red_intensity;
    int green_intensity;
    int blue_intensity;

    if (color <= 255)
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
