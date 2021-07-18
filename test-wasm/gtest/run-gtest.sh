if test -f "./../../build/pastel_gtest"; then
    cp ./../../build/pastel_gtest static
else
    echo "pastel_gtest not found in build folder"
    exit 1
fi

if test -f "./../../build/pastel_gtest.wasm"; then
    cp ./../../build/pastel_gtest.wasm static
else 
    echo "pasteld_gtest.wasm not found in build folder"
    exit 1
fi

python3 server.py