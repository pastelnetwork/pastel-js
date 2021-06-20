if test -f "./../build/pasteld"; then
    cp ./../build/pasteld static
fi

if test -f "./../build/pasteld.wasm"; then
    cp ./../build/pasteld.wasm static
fi

python3 server.py