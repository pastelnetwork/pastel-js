if test -f "./../build/pasteld"; then
    cp ./../build/pasteld static
else 
    echo "pasteld not found in build folder"
    exit 1
fi

if test -f "./../build/pasteld.wasm"; then
    cp ./../build/pasteld.wasm static
else 
    echo "pasteld.wasm not found in build folder"
    exit 1
fi

python3 server.py