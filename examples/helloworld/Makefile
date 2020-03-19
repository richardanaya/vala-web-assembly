build:
	valac example.vala -C
	clang --target=wasm32 -nostdlib -I./ -Wl,--no-entry -Wl,-allow-undefined -Wl,--export-dynamic -I../..//glib -I/usr/lib64/glib-2.0/include -I /usr/include/ -o example.wasm example.c
serve:
	python -m http.server
