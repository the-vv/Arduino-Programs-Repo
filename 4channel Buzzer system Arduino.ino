//Quiz Buzzer System By Vishnu, vvtec.dev@gmail.com

bool f = false;
bool s = false;
bool reset = true;

const int source = 2;
const int one = 3;
const int onel = 4;
const int two = 5;
const int twol = 6;
const int three = 7;
const int threel = 8;
const int four = 9;
const int fourl = 10;
const int buz = 11;
const int res = 12; //reset button
const int ready = 13;

void first(int);
void second(int);
void fsecond(int); //function to find second
void resetf();

unsigned long int update;
unsigned long int ledb;

bool ledst;

int sp;

void setup()
{

    pinMode(one, INPUT_PULLUP);
    pinMode(onel, OUTPUT);
    pinMode(two, INPUT_PULLUP);
    pinMode(twol, OUTPUT);
    pinMode(three, INPUT_PULLUP);
    pinMode(threel, OUTPUT);
    pinMode(four, INPUT_PULLUP);
    pinMode(fourl, OUTPUT);
    pinMode(buz, OUTPUT);
    pinMode(res, INPUT_PULLUP);
    pinMode(ready, OUTPUT);
    pinMode(source, OUTPUT);

    digitalWrite(ready, HIGH);
    digitalWrite(onel, LOW);
    digitalWrite(twol, LOW);
    digitalWrite(threel, LOW);
    digitalWrite(fourl, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(buz, LOW);
    Serial.println("ready");

    Serial.begin(9600);
    Serial.println("start");
}

void loop()
{

    resetf();

    if (f == false)
    {
        digitalWrite(ready, HIGH);
        if (f == false)
        {
            if (digitalRead(one) == LOW && f == false)
                first(3);
            else if (digitalRead(two) == LOW && f == false)
                first(5);
            else if (digitalRead(three) == LOW && f == false)
                first(7);
            else if (digitalRead(four) == LOW && f == false)
                first(9);
        }
    }
    if (millis() - update >= 500)
    {
        digitalWrite(buz, LOW);
    }
    if (!reset)
    {
        Serial.println("loop");
        if (millis() - update >= 500)
        {
            digitalWrite(buz, LOW);
        }
        if (millis() - ledb >= 300)
        {
            if (ledst == true)
            {
                digitalWrite(sp, LOW);
                ledst = false;
                ledb = millis();
            }
            else
            {
                digitalWrite(sp, HIGH);
                ledst = true;
                ledb = millis();
            }
        }
    }
}

void first(int a)
{
    f = true;
    Serial.println("first");
    reset = false;
    digitalWrite(ready, LOW);
    digitalWrite(a + 1, HIGH);
    digitalWrite(buz, HIGH);
    update = millis();
    fsecond(a);
}

void fsecond(int c)
{
    while (f == true && s == false)
    {
        if (millis() - update >= 500)
        {
            digitalWrite(buz, LOW);
        }
        if (c != 3)
        {
            if (digitalRead(one) == LOW)
                second(3);
        }
        if (c != 5)
        {
            if (digitalRead(two) == LOW)
                second(5);
        }
        if (c != 7)
        {
            if (digitalRead(three) == LOW)
                second(7);
        }
        if (c != 9)
        {
            if (digitalRead(four) == LOW)
                second(9);
        }
        resetf();
    }
}

void second(int b)
{
    s = true;
    Serial.println("second");
    reset = false;
    sp = b + 1;
    digitalWrite(b + 1, HIGH);
    ledb = millis();
    ledst = true;
    digitalWrite(buz, HIGH);
    update = millis();
}

void resetf()
{
    if (digitalRead(res) == LOW)
    {
        reset = true;
        f = false;
        s = false;
        digitalWrite(ready, HIGH);
        digitalWrite(onel, LOW);
        digitalWrite(twol, LOW);
        digitalWrite(threel, LOW);
        digitalWrite(fourl, LOW);
        digitalWrite(buz, HIGH);
        update = millis();
        Serial.println("ready");
    }
}

//about finished
