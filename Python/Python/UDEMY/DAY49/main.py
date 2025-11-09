from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException, TimeoutException
from dotenv import load_dotenv
import os
import time

load_dotenv()

ACCOUNT_EMAIL = os.getenv("ACCOUNT_EMAIL")
ACCOUNT_PASSWORD = os.getenv("ACCOUNT_PASSWORD")
PHONE = os.getenv("PHONE")

LINKEDIN_LOGIN_URL = "https://www.linkedin.com/login"
JOB_POST_URL = "https://www.linkedin.com/jobs/view/EXAMPLE_JOB_ID/" 

driver = webdriver.Chrome()
wait = WebDriverWait(driver, 10) 

try:
    driver.get(LINKEDIN_LOGIN_URL)

    email_field = wait.until(EC.presence_of_element_located((By.ID, "username")))
    email_field.send_keys(ACCOUNT_EMAIL)
    
    password_field = driver.find_element(By.ID, "password")
    password_field.send_keys(ACCOUNT_PASSWORD)
    password_field.send_keys(Keys.ENTER)

    driver.get(JOB_POST_URL)
# CORRECT
    apply_button = wait.until(EC.element_to_be_clickable((By.CSS_SELECTOR, ".jobs-s-apply button")))
    apply_button.click()

    try:
        phone = wait.until(EC.presence_of_element_located((By.CLASS_NAME, "fb-single-line-text__input")))
        
        if phone.get_attribute("value") == "":
            phone.send_keys(PHONE)
            
        submit_button = wait.until(EC.element_to_be_clickable((By.CSS_SELECTOR, "footer button")))
        submit_button.click()
        
        print("Application submitted!")

    except TimeoutException:
        print("Could not find the 'Easy Apply' fields. This might be a complex application.")
    except NoSuchElementException:
        print("Application fields not found. Skipping.")

    time.sleep(10)

finally:
    driver.quit()