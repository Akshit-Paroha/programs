#include<iostream>
using namespace std;

class camera
{
	private:
		int megapixels;
		
	public:
		
		void setmegapix(int m)
		{
			megapixels = m;
		}
		
		void showmegapix()
		{
			cout<<"Camera Megapixel: "<<megapixels<<endl;
		}
};

class gps
{
	private:
		string generation;
	
	public:
		
		void setgeneration(string g)
		{
			generation=g;
		}
		
		void showgeneration()
		{
			cout<<"GPS generation: "<<generation<<endl;
		}
};

class smartphone : public camera, public gps
{
	private:
		int price;
		
	public:
		
		void setsmartphone(int m,string g,int p)
		{
			setmegapix(m);
			setgeneration(g);
			price=p;
		}
		
		void showsmartphone()
		{
			showmegapix();
			showgeneration();
			cout<<"smartphone price: "<<price<<endl;
		}
};

int main()
{
	smartphone a;
	a.setsmartphone(50,"super accurate gen 4",35000);
	a.showsmartphone();
}
