  #include "Produkt.h"
  

  class Katalog
  { 
        public:
        Katalog();
         
        void wyswietlprodukt();
        
        void dodaj (Produkt &p);
        
        
        Produkt katalog_[10];
        int rozmiar;
    
  };
