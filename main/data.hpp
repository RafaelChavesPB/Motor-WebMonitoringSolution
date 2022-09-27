#ifndef DATA
#define DATA

    struct data {
        long long va, vb, vc;
        long long ia, ib, ic;
        unsigned long long created_at;
        const double convFactor = 5.0/((1LL << 23)-1);

        void operator=( const data &other){
            this->va = other.va;
            this->vb = other.vb;
            this->vc = other.vc;
            this->ia = other.ia;
            this->ib = other.ib;
            this->ic = other.ic;
        }

        data(){
            this->va = 0;
            this->vb = 0;
            this->vc = 0;
            this->ia = 0;
            this->ib = 0;
            this->ic = 0;
            this->created_at = 0;
        }
        
        data(long long values[], unsigned long long &time){
            this->va = values[0];
            this->vb = values[1];
            this->vc = values[2];
            this->ia = values[3];
            this->ib = values[4];
            this->ic = values[5];
            this->created_at = time;
        }
    };

#endif