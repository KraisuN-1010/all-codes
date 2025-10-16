import qrcode
import qrcode.constants
from PIL import Image
from qrcode.image.pil import PilImage

def generate_qr_code(data, filename="qrcode.png", fill_color="black", back_color="white"):
    """
    Generate a QR code from the given data.
    
    Args:
        data (str): The data to encode in the QR code
        filename (str): The output filename for the QR code image
        fill_color (str): The color of the QR code pattern
        back_color (str): The background color
    
    Returns:
        str: The filename of the generated QR code
    """
    # Create QR code instance
    qr = qrcode.QRCode(
        version=1,  # Controls the size (1 is 21x21, None means auto-size)
        error_correction=qrcode.constants.ERROR_CORRECT_H,  # High error correction
        box_size=10,  # Size of each box in pixels
        border=4,  # Border size in boxes
    )
    
    # Add data to the QR code
    qr.add_data(data)
    qr.make(fit=True)
    
    # Create an image from the QR code
    img = qr.make_image(fill_color=fill_color, back_color=back_color)
    
    # Save the image
    with open(filename, "wb") as f:
        img.save(f)
    print(f"QR code generated successfully: {filename}")
    
    return filename


def generate_qr_with_logo(data, logo_path, filename="qrcode_with_logo.png"):
    """
    Generate a QR code with a logo in the center.
    
    Args:
        data (str): The data to encode in the QR code
        logo_path (str): Path to the logo image
        filename (str): The output filename for the QR code image
    
    Returns:
        str: The filename of the generated QR code
    """
    # Create QR code
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_H,
        box_size=10,
        border=4,
    )
    
    qr.add_data(data)
    qr.make(fit=True)
    
    # Create QR code image
    qr_img = qr.make_image(image_factory=PilImage, fill_color="black", back_color="white").convert('RGB')
    
    # Open and resize logo
    logo = Image.open(logo_path)
    
    # Calculate logo size (should be about 1/5 of QR code size)
    qr_width, qr_height = qr_img.size
    logo_size = qr_width // 5
    
    # Resize logo
    logo = logo.resize((logo_size, logo_size), Image.Resampling.LANCZOS)
    
    # Calculate position to paste logo (center)
    logo_pos = ((qr_width - logo_size) // 2, (qr_height - logo_size) // 2)
    
    # Paste logo onto QR code
    qr_img.paste(logo, logo_pos)
    
    # Save the image
    qr_img.save(filename)
    print(f"QR code with logo generated successfully: {filename}")
    
    return filename


# Example usage
if __name__ == "__main__":
    # Example 1: Generate a basic QR code
    data = "hello best friend how are you?"
    generate_qr_code(data, "my_qrcode.png")
    
    # Example 2: Generate a QR code with custom colors
    generate_qr_code(
        "Hello, World!",
        "colored_qrcode.png",
        fill_color="navy",
        back_color="lightblue"
    )
    
    # Example 3: Generate a QR code with a logo (uncomment if you have a logo)
    # generate_qr_with_logo("https://www.example.com", "logo.png", "qr_with_logo.png")
    
    print("\nAll QR codes generated!")