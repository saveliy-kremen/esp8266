@echo Compiling proto file(s)...

for %%f in (google\protobuf\*.proto) do protoc --plugin=protoc-gen-nanopb=c:\nanopb\generator-bin\protoc-gen-nanopb.exe --nanopb_out=../services %%f

for %%f in (*.proto) do protoc --plugin=protoc-gen-nanopb=c:\nanopb\generator-bin\protoc-gen-nanopb.exe --nanopb_out=../services %%f

@echo Done

