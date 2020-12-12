class Produs
{
    char denumire[30];
    double pretUnitar;
    int stoc;
public:
    //initializare cu un constructor implicit
    Produs();
    //initializare cu un constructor cu argumente
    Produs(char *denumire, double pretUnitar, int stoc);
    void afisare();
    double pretTVA();

    void setDenumire(char *v);
    void setPretUnitar(double v);
    void setStoc(int v);

    char* getDenumire();
    double getPretUnitar();
    int getStoc();
    ~Produs();
};


