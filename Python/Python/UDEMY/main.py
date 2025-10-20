from flask import Flask, render_template_string, request, redirect, url_for, session, send_file
from PIL import Image, ImageDraw, ImageFont
import io
import os
import uuid

app = Flask(__name__)
# IMPORTANT: Change this secret key in a real application!
app.secret_key = 'a-truly-random-secret-key-for-production'

# --- HTML TEMPLATES (Unchanged) ---
HOME_TEMPLATE = """
<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0"><title>Visiting Card Generator</title><style>*{margin:0;padding:0;box-sizing:border-box}body{font-family:'Segoe UI',Tahoma,Geneva,Verdana,sans-serif;background:linear-gradient(135deg,#667eea 0%,#764ba2 100%);min-height:100vh;padding:20px}.container{max-width:600px;margin:50px auto;background:white;padding:40px;border-radius:15px;box-shadow:0 10px 40px rgba(0,0,0,.2)}h1{color:#333;text-align:center;margin-bottom:10px}.subtitle{text-align:center;color:#666;margin-bottom:30px}.form-group{margin-bottom:20px}label{display:block;margin-bottom:8px;color:#333;font-weight:500}input,textarea{width:100%;padding:12px;border:2px solid #e0e0e0;border-radius:8px;font-size:14px;transition:border-color .3s}input:focus,textarea:focus{outline:none;border-color:#667eea}textarea{resize:vertical;min-height:80px}button{width:100%;padding:15px;background:linear-gradient(135deg,#667eea 0%,#764ba2 100%);color:white;border:none;border-radius:8px;font-size:16px;font-weight:600;cursor:pointer;transition:transform .2s}button:hover{transform:translateY(-2px)}.required{color:red}</style></head><body><div class="container"><h1>✨ Visiting Card Generator</h1><p class="subtitle">Create your professional digital visiting card</p><form method="POST" action="/select-template"><div class="form-group"><label>Full Name <span class="required">*</span></label><input type="text" name="name" required placeholder="John Doe"></div><div class="form-group"><label>Job Title <span class="required">*</span></label><input type="text" name="title" required placeholder="Software Engineer"></div><div class="form-group"><label>Company Name</label><input type="text" name="company" placeholder="Tech Corp Inc."></div><div class="form-group"><label>Email <span class="required">*</span></label><input type="email" name="email" required placeholder="john@example.com"></div><div class="form-group"><label>Phone <span class="required">*</span></label><input type="tel" name="phone" required placeholder="+1 234 567 8900"></div><div class="form-group"><label>Website</label><input type="url" name="website" placeholder="www.example.com"></div><div class="form-group"><label>Address</label><textarea name="address" placeholder="123 Business Street, City, State"></textarea></div><button type="submit">Next: Choose Template →</button></form></div></body></html>
"""
TEMPLATE_SELECT = """
<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0"><title>Select Template</title><style>*{margin:0;padding:0;box-sizing:border-box}body{font-family:'Segoe UI',Tahoma,Geneva,Verdana,sans-serif;background:linear-gradient(135deg,#667eea 0%,#764ba2 100%);min-height:100vh;padding:20px}.container{max-width:1200px;margin:30px auto;background:white;padding:40px;border-radius:15px;box-shadow:0 10px 40px rgba(0,0,0,.2)}h1{color:#333;text-align:center;margin-bottom:40px}.templates-grid{display:grid;grid-template-columns:repeat(auto-fit,minmax(300px,1fr));gap:30px;margin-bottom:30px}.template-card{border:3px solid #e0e0e0;border-radius:12px;padding:20px;cursor:pointer;transition:all .3s;position:relative}.template-card:hover{border-color:#667eea;transform:translateY(-5px);box-shadow:0 5px 20px rgba(0,0,0,.1)}.template-card.selected{border-color:#667eea;background:#f8f9ff}.template-preview{background:#f5f5f5;padding:20px;border-radius:8px;margin-bottom:15px;min-height:200px}.template-name{font-size:18px;font-weight:600;color:#333;text-align:center}.template-desc{font-size:14px;color:#666;text-align:center;margin-top:5px}.submit-btn{width:100%;max-width:300px;margin:0 auto;display:block;padding:15px;background:linear-gradient(135deg,#667eea 0%,#764ba2 100%);color:white;border:none;border-radius:8px;font-size:16px;font-weight:600;cursor:pointer;transition:transform .2s}.submit-btn:hover{transform:translateY(-2px)}.submit-btn:disabled{opacity:.5;cursor:not-allowed}input[type=radio]{display:none}.preview-modern{background:linear-gradient(135deg,#2c3e50 0%,#3498db 100%);color:white;padding:30px}.preview-classic{background:white;border:2px solid #333;color:#333;padding:30px}.preview-elegant{background:linear-gradient(135deg,#1a1a1a 0%,#4a4a4a 100%);color:#d4af37;padding:30px}.preview-minimal{background:#f8f9fa;border-left:5px solid #667eea;color:#333;padding:30px}.preview-bold{background:linear-gradient(135deg,#e74c3c 0%,#c0392b 100%);color:white;padding:30px}</style></head><body><div class="container"><h1>🎨 Choose Your Card Template</h1><form method="POST" action="/generate-card"><div class="templates-grid"><label class="template-card" onclick="selectTemplate(this)"><input type="radio" name="template" value="modern" required><div class="template-preview preview-modern"><h3 style="margin-bottom:10px">Your Name</h3><p style="font-size:14px;opacity:.9">Job Title</p><div style="margin-top:20px;font-size:12px;opacity:.8"><p>📧 email@example.com</p><p>📱 +1 234 567 8900</p></div></div><div class="template-name">Modern Blue</div><div class="template-desc">Professional gradient design</div></label><label class="template-card" onclick="selectTemplate(this)"><input type="radio" name="template" value="classic"><div class="template-preview preview-classic"><h3 style="margin-bottom:10px;font-weight:bold">YOUR NAME</h3><p style="font-size:14px;margin-bottom:20px">Job Title</p><div style="font-size:12px"><p>email@example.com</p><p>+1 234 567 8900</p></div></div><div class="template-name">Classic White</div><div class="template-desc">Timeless and elegant</div></label><label class="template-card" onclick="selectTemplate(this)"><input type="radio" name="template" value="elegant"><div class="template-preview preview-elegant"><h3 style="margin-bottom:10px;font-weight:300">Your Name</h3><p style="font-size:14px;opacity:.9">Job Title</p><div style="margin-top:20px;font-size:12px;opacity:.8"><p>✉ email@example.com</p><p>☎ +1 234 567 8900</p></div></div><div class="template-name">Elegant Gold</div><div class="template-desc">Luxury dark theme</div></label><label class="template-card" onclick="selectTemplate(this)"><input type="radio" name="template" value="minimal"><div class="template-preview preview-minimal"><h3 style="margin-bottom:10px;color:#667eea">Your Name</h3><p style="font-size:14px;margin-bottom:20px">Job Title</p><div style="font-size:12px;color:#666"><p>email@example.com</p><p>+1 234 567 8900</p></div></div><div class="template-name">Minimal</div><div class="template-desc">Clean and simple</div></label><label class="template-card" onclick="selectTemplate(this)"><input type="radio" name="template" value="bold"><div class="template-preview preview-bold"><h3 style="margin-bottom:10px;font-weight:bold">YOUR NAME</h3><p style="font-size:14px;opacity:.95">JOB TITLE</p><div style="margin-top:20px;font-size:12px;opacity:.9"><p>📧 EMAIL@EXAMPLE.COM</p><p>📱 +1 234 567 8900</p></div></div><div class="template-name">Bold Red</div><div class="template-desc">Strong and impactful</div></label></div><button type="submit" class="submit-btn" id="submitBtn" disabled>Generate My Card →</button></form></div><script>function selectTemplate(e){document.querySelectorAll(".template-card").forEach(e=>e.classList.remove("selected")),e.classList.add("selected"),document.getElementById("submitBtn").disabled=!1}</script></body></html>
"""
PROFILE_TEMPLATE = """
<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0"><title>Your Visiting Card</title><style>*{margin:0;padding:0;box-sizing:border-box}body{font-family:'Segoe UI',Tahoma,Geneva,Verdana,sans-serif;background:linear-gradient(135deg,#667eea 0%,#764ba2 100%);min-height:100vh;padding:20px}.container{max-width:900px;margin:30px auto;background:white;padding:40px;border-radius:15px;box-shadow:0 10px 40px rgba(0,0,0,.2)}h1{color:#333;text-align:center;margin-bottom:30px}.card-preview{margin-bottom:30px;text-align:center}.card-image{max-width:100%;border-radius:10px;box-shadow:0 5px 20px rgba(0,0,0,.15)}.upload-section{background:#f8f9fa;padding:30px;border-radius:10px;margin-bottom:30px}.upload-section h2{color:#333;margin-bottom:20px;font-size:20px}.upload-options{display:flex;gap:20px;margin-bottom:20px;flex-wrap:wrap}.upload-btn{flex:1;min-width:200px;padding:15px;background:#667eea;color:white;border:none;border-radius:8px;font-size:14px;cursor:pointer;transition:all .3s}.upload-btn:hover{background:#5568d3;transform:translateY(-2px)}input[type=file]{display:none}.video-container{display:none;margin-top:20px}video{width:100%;max-width:400px;border-radius:8px;margin-bottom:10px}.capture-btn{padding:10px 20px;background:#28a745;color:white;border:none;border-radius:5px;cursor:pointer}.download-section{display:flex;gap:15px;justify-content:center;flex-wrap:wrap}.download-btn{padding:15px 30px;border:none;border-radius:8px;font-size:16px;font-weight:600;cursor:pointer;transition:all .3s;text-decoration:none;display:inline-block}.download-png{background:#28a745;color:white}.download-pdf{background:#dc3545;color:white}.download-btn:hover{transform:translateY(-2px);box-shadow:0 5px 15px rgba(0,0,0,.2)}.success-msg{background:#d4edda;color:#155724;padding:15px;border-radius:8px;margin-bottom:20px;text-align:center}.back-btn{display:block;text-align:center;margin-top:20px;color:#667eea;text-decoration:none;font-weight:600}.back-btn:hover{text-decoration:underline}</style></head><body><div class="container"><h1>🎉 Your Visiting Card is Ready!</h1>{% if success %}<div class="success-msg">✓ Profile image uploaded successfully!</div>{% endif %}<div class="card-preview"><img src="{{ card_image }}" alt="Your Visiting Card" class="card-image"></div><div class="upload-section"><h2>📸 Add Your Profile Photo</h2><form method="POST" action="/upload-photo" enctype="multipart/form-data"><div class="upload-options"><button type="button" class="upload-btn" onclick="document.getElementById('fileInput').click()">📁 Upload from File</button><input type="file" id="fileInput" name="photo" accept="image/*" onchange="this.form.submit()"><button type="button" class="upload-btn" onclick="startCamera()">📷 Take Live Photo</button></div></form><div class="video-container" id="videoContainer"><video id="video" autoplay></video><canvas id="canvas" style="display:none"></canvas><button class="capture-btn" onclick="capturePhoto()">Capture Photo</button><button class="capture-btn" style="background:#dc3545;margin-left:10px" onclick="stopCamera()">Cancel</button></div></div><div class="download-section"><a href="/download/png" class="download-btn download-png">⬇ Download PNG</a><a href="/download/pdf" class="download-btn download-pdf">⬇ Download PDF</a></div><a href="/" class="back-btn">← Create Another Card</a></div><script>let stream=null;async function startCamera(){const e=document.getElementById("video"),t=document.getElementById("videoContainer");try{stream=await navigator.mediaDevices.getUserMedia({video:!0}),e.srcObject=stream,t.style.display="block"}catch(e){alert("Unable to access camera: "+e.message)}}function stopCamera(){document.getElementById("video");const e=document.getElementById("videoContainer");stream&&stream.getTracks().forEach(e=>e.stop()),e.style.display="none"}function capturePhoto(){const e=document.getElementById("video"),t=document.getElementById("canvas"),a=t.getContext("2d");t.width=e.videoWidth,t.height=e.videoHeight,a.drawImage(e,0,0),t.toBlob(e=>{const t=new FormData;t.append("photo",e,"camera-photo.jpg"),fetch("/upload-photo",{method:"POST",body:t}).then(e=>{e.ok&&location.reload()})},"image/jpeg"),stopCamera()}</script></body></html>
"""

def create_card_image(user_data, template_type):
    width, height = 1050, 600
    if template_type == 'modern':
        img = Image.new('RGB', (width, height), color=(44, 62, 80))
        draw = ImageDraw.Draw(img)
        for i in range(height):
            r, g, b = int(44 + 8*i/height), int(62 + 90*i/height), int(80 + 139*i/height)
            draw.rectangle([(0, i), (width, i+1)], fill=(r, g, b))
        text_color = (255, 255, 255)
    elif template_type == 'classic':
        img = Image.new('RGB', (width, height), color=(255, 255, 255))
        draw = ImageDraw.Draw(img)
        draw.rectangle([(10, 10), (width-10, height-10)], outline=(51, 51, 51), width=5)
        text_color = (51, 51, 51)
    elif template_type == 'elegant':
        img = Image.new('RGB', (width, height), color=(26, 26, 26))
        draw = ImageDraw.Draw(img)
        text_color = (212, 175, 55)
    elif template_type == 'minimal':
        img = Image.new('RGB', (width, height), color=(248, 249, 250))
        draw = ImageDraw.Draw(img)
        draw.rectangle([(0, 0), (10, height)], fill=(102, 126, 234))
        text_color = (51, 51, 51)
    else: # bold
        img = Image.new('RGB', (width, height), color=(231, 76, 60))
        draw = ImageDraw.Draw(img)
        text_color = (255, 255, 255)

    profile_image_filename = user_data.get('profile_image_filename')
    if profile_image_filename:
        try:
            uploads_dir = os.path.join(app.root_path, 'uploads')
            image_path = os.path.join(uploads_dir, profile_image_filename)
            if os.path.exists(image_path):
                with Image.open(image_path) as profile_img:
                    profile_img = profile_img.resize((150, 150))
                    mask = Image.new('L', (150, 150), 0)
                    ImageDraw.Draw(mask).ellipse((0, 0, 150, 150), fill=255)
                    img.paste(profile_img, (50, 50), mask)
            else:
                profile_image_filename = None
        except Exception as e:
            print(f"Error processing profile image: {e}")
            profile_image_filename = None
    
    text_x = 220 if profile_image_filename else 50
    
    try:
        font_name = ImageFont.truetype("arial.ttf", 48)
        font_title = ImageFont.truetype("arial.ttf", 32)
        font_info = ImageFont.truetype("arial.ttf", 24)
    except IOError:
        font_name, font_title, font_info = [ImageFont.load_default()] * 3
    
    draw.text((text_x, 80), user_data.get('name', ''), fill=text_color, font=font_name)
    draw.text((text_x, 150), user_data.get('title', ''), fill=text_color, font=font_title)
    if user_data.get('company'): draw.text((text_x, 200), user_data['company'], fill=text_color, font=font_info)
    
    y_offset = 280
    contact_items = [('📧 ', user_data.get('email', '')), ('📱 ', user_data.get('phone', ''))]
    if user_data.get('website'): contact_items.append(('🌐 ', user_data['website']))
    if user_data.get('address'): contact_items.append(('📍 ', user_data['address'][:50]))
    for icon, text in contact_items:
        draw.text((text_x, y_offset), f"{icon}{text}", fill=text_color, font=font_info)
        y_offset += 50
    return img

@app.route('/')
def index():
    return render_template_string(HOME_TEMPLATE)

@app.route('/select-template', methods=['POST'])
def select_template():
    session.clear()
    session['user_data'] = {k: request.form.get(k, '') for k in ['name', 'title', 'company', 'email', 'phone', 'website', 'address']}
    return render_template_string(TEMPLATE_SELECT)

@app.route('/generate-card', methods=['POST'])
def generate_card():
    session['template'] = request.form['template']
    user_data = session.get('user_data', {})
    img = create_card_image(user_data, session['template'])
    img_io = io.BytesIO()
    img.save(img_io, 'PNG')
    generated_dir = os.path.join(app.root_path, 'generated_cards')
    os.makedirs(generated_dir, exist_ok=True)
    filename = f"{uuid.uuid4().hex}.png"
    with open(os.path.join(generated_dir, filename), 'wb') as f: f.write(img_io.getvalue())
    session['card_file'] = filename
    return redirect(url_for('profile'))

@app.route('/upload-photo', methods=['POST'])
def upload_photo():
    if 'photo' not in request.files or not request.files['photo'].filename:
        return redirect(url_for('profile'))
    photo = request.files['photo']
    uploads_dir = os.path.join(app.root_path, 'uploads')
    os.makedirs(uploads_dir, exist_ok=True)
    user_data = session.get('user_data', {})
    if old_filename := user_data.get('profile_image_filename'):
        try: os.remove(os.path.join(uploads_dir, old_filename))
        except OSError as e: print(f"Error deleting old photo: {e}")
    # Ensure filename is a str (not None) before calling splitext to satisfy type checkers
    filename = photo.filename or ""
    _, f_ext = os.path.splitext(filename)
    if not f_ext:
        # Provide a safe default extension if the uploaded file has none
        f_ext = ".jpg"
    profile_filename = f"{uuid.uuid4().hex}{f_ext}"
    photo.save(os.path.join(uploads_dir, profile_filename))
    user_data['profile_image_filename'] = profile_filename
    session['user_data'] = user_data
    img = create_card_image(user_data, session.get('template', 'modern'))
    img_bytes = io.BytesIO()
    img.save(img_bytes, 'PNG')
    generated_dir = os.path.join(app.root_path, 'generated_cards')
    os.makedirs(generated_dir, exist_ok=True)
    if old_card_file := session.get('card_file'):
        try: os.remove(os.path.join(generated_dir, old_card_file))
        except OSError as e: print(f"Error deleting old card: {e}")
    new_card_filename = f"{uuid.uuid4().hex}.png"
    with open(os.path.join(generated_dir, new_card_filename), 'wb') as f: f.write(img_bytes.getvalue())
    session['card_file'] = new_card_filename
    return redirect(url_for('profile', success=True))

@app.route('/profile')
def profile():
    if not session.get('card_file'): return redirect(url_for('index'))
    card_url = url_for('generated_file', filename=session['card_file'], v=uuid.uuid4().hex)
    return render_template_string(PROFILE_TEMPLATE, card_image=card_url, success=request.args.get('success'))

@app.route('/generated/<filename>')
def generated_file(filename):
    return send_file(os.path.join(app.root_path, 'generated_cards', filename), mimetype='image/png')

@app.route('/download/<format>')
def download(format):
    if not (card_file := session.get('card_file')): return redirect(url_for('index'))
    file_path = os.path.join(app.root_path, 'generated_cards', card_file)
    if not os.path.exists(file_path):
        return "Error: File not found. Please create a new card.", 404
    if format == 'png':
        return send_file(file_path, as_attachment=True, download_name='visiting_card.png')
    elif format == 'pdf':
        with Image.open(file_path) as img:
            img_rgb = img.convert("RGB")
            pdf_io = io.BytesIO()
            img_rgb.save(pdf_io, "PDF", resolution=100.0)
            pdf_io.seek(0)
        return send_file(pdf_io, as_attachment=True, download_name='visiting_card.pdf', mimetype='application/pdf')
    return redirect(url_for('profile'))

if __name__ == '__main__':
    print("Starting Visiting Card Generator on http://127.0.0.1:5000")
    print("Files will be saved in 'generated_cards' and 'uploads' directories.")
    app.run(debug=True)