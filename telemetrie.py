import socket

UDP_IP = "0.0.0.0" 
UDP_PORT = 4210    

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print(f"Sistemul de telemetrie asculta pe portul {UDP_PORT}")
print("Se asteapta date de la ESP32...\n")

try:
    while True:
        data, addr = sock.recvfrom(1024)
        mesaj = data.decode('utf-8')
        print(f"[{addr[0]}] Telemetrie Live -> {mesaj}")
        
except KeyboardInterrupt:
    print("\nReceptor oprit.")
    sock.close()
