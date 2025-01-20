# Controle de LED RGB e Buzzer com Raspberry Pi Pico W via UART

Este projeto foi desenvolvido para controlar um LED RGB e um buzzer conectados a uma **Raspberry Pi Pico W** usando comunicação **UART**. A interação é realizada por meio do envio de comandos pelo software **PuTTY** ou por simulação no **Wokwi**. O programa foi implementado em **C** utilizando o **Pico SDK** (versão 2.1.0).

## Funcionalidades
1. **Controle do LED RGB**:  
   - **RED**: Liga o LED vermelho.  
   - **GREEN**: Liga o LED verde.  
   - **BLUE**: Liga o LED azul.  
   - **WHITE**: Liga todos os LEDs (vermelho, verde e azul simultaneamente).  
   - **OFF**: Apaga todos os LEDs.

2. **Controle do Buzzer**:  
   - **BUZZER**: Ativa o buzzer para emitir um beep por durante 300 milissegundos.

## Configuração do Ambiente
Para rodar este projeto, é necessário configurar o ambiente de desenvolvimento e instalar as ferramentas a seguir:
- **GNU Arm Embedded Toolchain** (`arm-none-eabi-gcc`).
- **Pico SDK** (versão 2.1.0).
- Extensões para o VS Code:
  - **CMake**.
  - **Raspberry Pi Pico**.
  - **Wokwi**.

## Simulação no Wokwi
O projeto foi configurado para ser simulado no [Wokwi](https://wokwi.com/). O diagrama do circuito já está integrado e permite verificar o funcionamento do LED RGB e do buzzer com os comandos enviados via UART.

## Instruções de Uso
1. **Preparação do Hardware**:  
   - Conecte os terminais do LED RGB e o buzzer aos pinos GPIO da **Raspberry Pi Pico W**.
   - Certifique-se de que os resistores adequados estão conectados ao LED RGB.

2. **Baud Rate**:  
   - A comunicação UART está configurada para um baud rate de **115200**.

3. **Execução do Código**:
   - Importe o projeto para o **VS Code** usando o menu de importação da extensão da Raspberry Pi Pico.
   - Compile e envie o código para a placa.

4. **Comandos UART**:  
   Use o **PuTTY** ou qualquer outro terminal UART para enviar os comandos:
   - **RED**: Liga o LED vermelho.
   - **GREEN**: Liga o LED verde.
   - **BLUE**: Liga o LED azul.
   - **WHITE**: Liga todos os LEDs.
   - **OFF**: Desliga todos os LEDs.
   - **BUZZER**: Ativa o buzzer.

## Estrutura do Projeto
- `src/`: Código-fonte do projeto.
- `include/`: Arquivos de cabeçalho.
- `CMakeLists.txt`: Configuração para compilação com o CMake.
- `wokwi_diagram.json`: Configuração do circuito para simulação no Wokwi.

## Contribuições
Contribuições são bem-vindas! Caso tenha sugestões, problemas ou melhorias, sinta-se à vontade para abrir uma **issue** ou enviar um **pull request**.

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).

---

Projeto desenvolvido por **Carlos Valadão** e **Victor Samir**.

