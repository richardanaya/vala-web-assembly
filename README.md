# Vala and web assembly

It appears as though its possible to generate web assembly using the [vala compiler](https://wiki.gnome.org/Projects/Vala). Unfortunately, `glib` doesn't compile out of the box for some very minor reasons. This repo contains working glib headers and various example of testing out the capabilities of vala.

Changes to glib:
* removed gthreads header
* disabled an assertion

## dependencies
```
sudo dnf install clang llvm lld vala glib-devel
```

## example
```vala
// classes work like normal!
class Calculator {
	public static int add(int a, int b){
		return a+b;
	}
}

// Entry functions need some special sugar to expose them properly
[CCode (cname = "__attribute__((visibility(\"default\"))) add")]
public int add(int a, int b){
	return Calculator.add(a,b);
}

```

See it working [here](https://richardanaya.github.io/vala-web-assembly/examples/add/index.html)


## hello world to browser

I utilize a tech called [`js_ffi`](https://github.com/richardanaya/js_ffi) which can communicate with browser DOM

```vala
extern float jsffiregister(char* msg);
extern float jsfficall1(float context,float fn,float arg_1_type,float arg_1_value);

const float JS_UNDEFINED = 0.0f;
const float TYPE_STRING = 2.0f;

// Entry functions need some special sugar to expose them properly
// vala has some weird logic around functions named main so we prefix _
[CCode (cname = "__attribute__((visibility(\"default\"))) main")]
public void _main(){
	var log = jsffiregister("window.alert");
	jsfficall1(JS_UNDEFINED,log,TYPE_STRING,(float)(int)"Hello World!");
}
```

```html
<script src="https://cdn.jsdelivr.net/gh/richardanaya/js_ffi@latest/js_ffi.js"></script>
<script>js_ffi.run("example.wasm");</script>
```

See it working [here](https://richardanaya.github.io/vala-web-assembly/examples/helloworld/index.html)
