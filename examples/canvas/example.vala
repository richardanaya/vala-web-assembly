extern float jsffiregister(char* msg);
extern float jsfficall1(float context,float fn,float arg_1_type,float arg_1_value);

const float JS_UNDEFINED = 0.0f;
const float TYPE_STRING = 2.0f;

class Game {
	public void go(){
		var log = jsffiregister("window.alert");
		jsfficall1(0,log,TYPE_STRING,(float)(int)"Hello World!");
	}
}

// Entry functions need some special sugar to expose them properly
[CCode (cname = "__attribute__((visibility(\"default\"))) main")]
public void _main(){
	var g = new Game();
	g.go();
}
