#define BOUCLE 10

int moyenne (int pin)
{
    int i = 0;
    int moy = 0;
    while (i <= BOUCLE) {
        moy += analogread(pin);
        i++;
    }

    return moy/BOUCLE;
}