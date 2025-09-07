# client.py
import asyncio
import websockets

FRIEND_IP = "192.168.175.20"
FRIEND_PORT = 5264

async def connect_to_server():
    uri = f"ws://{FRIEND_IP}:{FRIEND_PORT}"  # Correct URI with IP and port
    async with websockets.connect(uri) as websocket:
        print("Connected to server!")

        while True:
            message = input("Enter lowercase message: ")
            if message == "exit":
                print("Exiting.")
                break
            await websocket.send(message)
            reply = await websocket.recv()
            print(f"Uppercase from server: {reply}")

asyncio.run(connect_to_server())
