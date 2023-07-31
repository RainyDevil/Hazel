#include <Hazel.h>

class SandBox : public Hazel::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};
int main()
{
	SandBox* sandBox = new SandBox();
	sandBox->Run();
	delete sandBox;
	return 0;
}