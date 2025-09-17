const fs = require('fs')

const handleRequests = (req, res) => {
  console.log(req.url, req.method);
  const htmlHome = `
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Welcome Page</title>
        <style>
            body {
                font-family: sans-serif;
                text-align: center;
                margin-top: 50px;
            }
            a {
                font-size: 1.2em;
            }
        </style>
    </head>
    <body>

        <h1>Welcome to the Main Page!</h1>

        <p>
            <a href="calculator">Go to the Calculator</a>
        </p>

    </body>
    </html>
  `;
  const htmlCalculator = `
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Simple Calculator</title>
        <style>
            body {
                font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
                background-color: #f4f4f9;
                display: flex;
                justify-content: center;
                align-items: center;
                height: 100vh;
                margin: 0;
            }
            .container {
                background-color: white;
                padding: 30px;
                border-radius: 8px;
                box-shadow: 0 4px 8px rgba(0,0,0,0.1);
                text-align: center;
            }
            h1 {
                color: #333;
            }
            input {
                width: 90%;
                padding: 10px;
                margin-bottom: 15px;
                border: 1px solid #ddd;
                border-radius: 4px;
                font-size: 1em;
            }
            button {
                background-color: #007bff;
                color: white;
                border: none;
                padding: 12px 25px;
                border-radius: 4px;
                font-size: 1em;
                cursor: pointer;
                transition: background-color 0.3s ease;
            }
            button:hover {
                background-color: #0056b3;
            }
        </style>
    </head>
    <body>

        <div class="container">
            <h1>Calculator</h1>
            <form action="/calculate-result" method="POST">
                <div>
                    <input type="number" id="num1" name="num1" placeholder="Enter first number" required>
                </div>
                <div>
                    <input type="number" id="num2" name="num2" placeholder="Enter second number" required>
                </div>
                <button type="submit">Sum</button>
            </form>
        </div>

    </body>
    </html>
  `;
    // htmlResult will be generated dynamically after sum is calculated
  if (req.url === "/") {
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/html");
    res.write(htmlHome);
    return res.end();
  } else if (req.url === "/calculator") {
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/html");
    res.write(htmlCalculator);
    return res.end();
    }
}

const handleCalculation = (req, res) => {
    if (req.url === "/calculate-result" && req.method === "POST") {
        let body = '';
        req.on("data", (chunk) => {
            body += chunk.toString();
        });
        req.on("end", () => {
            const params = new URLSearchParams(body);
            const jsonObject = Object.fromEntries(params);
            const sum = parseInt(jsonObject.num1) + parseInt(jsonObject.num2);
            const htmlResult = `
                <!DOCTYPE html>
                <html lang="en">
                <head>
                    <meta charset="UTF-8">
                    <meta name="viewport" content="width=device-width, initial-scale=1.0">
                    <title>Calculation Result</title>
                    <style>
                        body {
                            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
                            background-color: #f4f4f9;
                            display: flex;
                            justify-content: center;
                            align-items: center;
                            height: 100vh;
                            margin: 0;
                        }
                        .container {
                            background-color: white;
                            padding: 30px;
                            border-radius: 8px;
                            box-shadow: 0 4px 8px rgba(0,0,0,0.1);
                            text-align: center;
                        }
                        h1 {
                            color: #333;
                        }
                        p {
                            font-size: 1.5em;
                            color: #007bff;
                            font-weight: bold;
                        }
                        a {
                            display: inline-block;
                            margin-top: 20px;
                            text-decoration: none;
                            color: #0056b3;
                        }
                    </style>
                </head>
                <body>

                    <div class="container">
                        <h1>Calculation Result</h1>
                        
                        <p>
                            The sum is: ${sum}
                        </p>

                        <a href="/calculator">Make another calculation</a>
                    </div>

                </body>
                </html>
            `;
            res.statusCode = 200;
            res.setHeader("Content-Type", "text/html");
            res.write(htmlResult);
            res.end();
        });
    }
}

module.exports = { handleRequests, handleCalculation };
