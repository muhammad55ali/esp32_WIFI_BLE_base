import socket
UDP_PORT = 3333

sock = socket.socket(socket.AF_INET,  # Internet
                     socket.SOCK_DGRAM)  # UDP

sock.bind(('', UDP_PORT)) # this is the line throwing the error

# sock.setblocking(0)
while True:
    data, address = sock.recvfrom(4096)
    print("received message:", data)