#include<iostream>
#include<vector>
using namespace std;

class vec{
    private :

        int size; //does not matter
        int* arr;
        int len;

        void expand(int sz){
            int len =2*sz;
            int* temp = arr;
            arr=new int[len];

            for(int i=0; i<sz; i++){
                arr[i]=temp[i];
            }

            delete[] temp;
        }


    public :

        
        
        vec(){
            arr = new int[1];
            size=0;
            len=1;
        }

        vec(int sz){
            len=1;
            while(len < sz){
                len*=2;
            }
            arr = new int[len];
            size=sz;

        }

        ~vec(){
            delete[] arr;
        }
        
        void pb(int val){
            
            if(size<len){
                arr[size]=val;
                size++;
            }
            else{
                expand(len);
                len*=2;
                arr[size]=val;
                size++;
            }
        }

        int Size(){
            return size;
        }
        
        vec(const vec& other) {
            size = other.size;
            len = other.len;

        arr = new int[len];

        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
        }

        int& operator[](int i){
            if(i>=size){
                throw out_of_range("Know thy limits");
            }
            return arr[i];
        }

        vec& operator=(vec b){
            delete[] arr;
            int sz= b.Size();
            size=0; //does not matter
            arr = new int[1];
            len=1;

            for(int i=0; i<sz; i++)
                (*this).pb(b[i]);

            return (*this);

        }

        bool operator==(vec b){
            if(size!=b.Size()) 
				return false;
            for(int i=0; i<b.Size();i++){
                if(b[i]!=(*this)[i]) 
					return false;
            }
            return true;
        }



};

int main() {
    vec a(68);
    for(int i=0; i<68; i++)
		a[i]=i+1;

    a.pb(68); 
	a.pb(69);

    vec Sahil;
    cout<<Sahil.Size()<<endl;
	Sahil.pb(0);
	vec Kahan;
	int bbg=0;
	Kahan.pb(bbg);
	   
	if(Kahan==Sahil)
		cout<<"YAY!"<<endl;
}

