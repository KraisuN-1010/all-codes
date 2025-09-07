# server.py
import asyncio
import websockets

async def handler(websocket):
    async for message in websocket:
        await websocket.send(message.upper())

async def main():
    async with websockets.serve(handler, "127.0.0.1", 5264):
        print("Server is running on localhost:5264")
        await asyncio.Future()  # run forever

asyncio.run(main())
