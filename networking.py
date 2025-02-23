import socket

def scan_port(ip, port):
    """Tries to connect to a given port on the IP."""
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(1)  # Timeout for the connection attempt
    try:
        s.connect((ip, port))
        s.close()
        return True
    except (socket.timeout, ConnectionRefusedError):
        return False

def scan_common_ports(ip):
    """Scans common ports on the target IP."""
    common_ports = [21, 22, 25, 53, 80, 110, 143, 443, 3306, 8080]
    print(f"Scanning common ports on {ip}...")
    for port in common_ports:
        if scan_port(ip, port):
            print(f"[+] Port {port} is OPEN")
        else:
            print(f"[-] Port {port} is CLOSED")

def scan_specific_port(ip, port):
    """Scans a specific port chosen by the user."""
    print(f"Scanning port {port} on {ip}...")
    if scan_port(ip, port):
        print(f"[+] Port {port} is OPEN")
    else:
        print(f"[-] Port {port} is CLOSED")

if __name__ == "__main__":
    target_ip = input("Enter the target IP address: ")
    scan_common_ports(target_ip)
    
    choice = input("Do you want to scan a specific port? (y/n): ")
    if choice.lower() == 'y':
        port = int(input("Enter the port number: "))
        scan_specific_port(target_ip, port)