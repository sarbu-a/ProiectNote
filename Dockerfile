FROM gcc:latest
WORKDIR /usr/src/app
COPY . .
RUN g++ -std=c++17 src/*.cpp -o ProiectNote
CMD ["./ProiectNote"]