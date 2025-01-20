# PicoWPutty

Este é um projeto para controlar LEDs e um buzzer usando um Raspberry Pi Pico W. O projeto utiliza a SDK do Raspberry Pi Pico e é escrito em C.

## Uso

1. Carregue o arquivo `picowputty.uf2` no Raspberry Pi Pico W.
2. Conecte-se ao dispositivo via UART.
3. Envie comandos para controlar os LEDs e o buzzer:
    - `RED`, `GREEN`, `BLUE` para acender os LEDs correspondentes.
    - `OFF` para desligar todos os LEDs.
    -  para ligar o buzzer por 2 segundos.

## Dependências

- Raspberry Pi Pico SDK
- CMake
- Ninja (opcional, mas recomendado)

## Configuração do Ambiente

1. Clone este repositório:
    ```sh
    git clone https://github.com/Samir21203/picowputty.git
    cd picowputty
    ```

2. Configure o SDK do Raspberry Pi Pico:
    ```sh
    export PICO_SDK_PATH=<CAMINHO_PARA_O_SDK>
    ```

3. Crie um diretório de build e navegue até ele:
    ```sh
    mkdir build
    cd build
    ```

4. Configure o projeto com CMake:
    ```sh
    cmake ..
    ```

5. Compile o projeto:
    ```sh
    make -j4
    ```

## Arquivos Principais

- : Código principal do projeto.
-  e : Funções para controle dos GPIOs e PWM.
-  e : Funções para comunicação UART.

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.
