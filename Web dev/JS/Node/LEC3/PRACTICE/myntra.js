const http = require("http");
const fs = require("fs");
const server = http.createServer((req, res) => {
  console.log(req.url, req.method);

  const htmlCodeHome = `
    <!DOCTYPE html>
    <html lang="en">
      <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>This is the home page</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
      </head>
      <body>
        <nav class="navbar navbar-expand-lg bg-body-tertiary">
          <div class="container-fluid">
            <a class="navbar-brand" href="#">Navbar</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
              <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
              <div class="navbar-nav">
                <a class="nav-link active" aria-current="page" href="#">Home</a>
                <a class="nav-link" href="hash">Features</a>
                <a class="nav-link" href="#">Pricing</a>
                <a class="nav-link disabled" aria-disabled="true">Disabled</a>
              </div>
            </div>
          </div>
        </nav>
        <h1>This is the home page</h1>
        <form action="/submit-details" method="POST">
          <input type="text" name="search" placeholder="Search products" />
          <button type="submit">Search</button>
        </form>

        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
      </body>
    </html>
  `;

  const htmlCodeProducts = `
    <html>
      <head>
        <title>This is the products page</title>  
      </head>
      <body>
        <h1>
          This is the products page
        </h1>
      </body>
    </html>  
  `;

  if (req.url === "/") {
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/html");
    res.write(htmlCodeHome);
    return res.end();
  } else if (req.url === "/products") {
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/html");
    res.write(htmlCodeProducts);
    return res.end();
  } else if (req.url === "/submit-details" && req.method === "POST") {
    // Collect the form data
    let body = '';
    
    req.on("data", (chunk) => {
      console.log("Chunk (Buffer):", chunk); // Log the raw Buffer
      console.log("Chunk (as string):", chunk.toString()); // Log the string representation
      console.log("Chunk length:", chunk.length); // Log buffer length
      console.log("Buffer bytes:", Array.from(chunk)); // Log individual bytes
      body += chunk.toString(); // Convert buffer to string and accumulate
    });

    req.on("end", () => {
      console.log("Finished receiving data");
      console.log("Complete form data:", body); // Log the complete parsed form data
      console.log("URL decoded form data:", decodeURIComponent(body)); // URL decode for readability
      
      // Set headers and redirect
      res.statusCode = 302;
      const params = new URLSearchParams(body);
      // for (const [key, value] of params.entries()) {
      //   jsonObject[key] = value;
      // }
      const jsonObject = Object.fromEntries(params);
      console.log(jsonObject);
      fs.writeFileSync("user-details.txt", JSON.stringify(jsonObject));
      res.setHeader("Location", "/");
      res.end();
    });

    req.on("error", (err) => {
      console.error("Error while receiving data:", err);
      res.statusCode = 500;
      res.setHeader("Content-Type", "text/html");
      res.end("<h1>Internal Server Error</h1>");
    });
    
    // IMPORTANT: Return here to prevent the code from continuing to the 404 handler
    return;
    
  } else if (req.url === "/hash") {
    const htmlCodeForHash = `
    <html>
      <head>
        <title>This is the Hash</title>  
      </head>
      <body>
        <h1>
          This is the features page
        </h1>
      </body>
    </html> 
    `;
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/html");
    res.write(htmlCodeForHash);
    return res.end();
  }

  // 404 handler - only reached if none of the above conditions match
  res.statusCode = 404;
  res.setHeader("Content-Type", "text/html");
  res.write(`
    <html>  
      <head>
        <title>Page Not Found</title>
      </head>
      <body>
        <h1>
          404 - Page Not Found
        </h1> 
      </body>
    </html>  
  `);
  res.end();
});

const PORT = 3000;

server.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}/`);
});