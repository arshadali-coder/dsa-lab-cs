# Deque Lab Report Generator

A static website for Netlify that generates a personalized PDF report for the CSL-302 Data Structure Lab assignment.

## Files
- `index.html` — the entire website; no build step required.

## Deploy to Netlify
1. Extract this ZIP file.
2. Open Netlify and sign in.
3. Choose **Add new site** → **Deploy manually** (wording may vary).
4. Drag the extracted `deque-report-generator` folder, or its contents, into the deploy drop zone.
5. Open the generated Netlify URL and test the form.

Alternatively, put `index.html` in a Git repository and import that repository into Netlify. Set the publish directory to `.` and leave the build command empty.

## Notes
- PDF generation happens in the browser using jsPDF loaded from cdnjs, so an internet connection is required when loading the page.
- Student details are not submitted to a backend.
- The report is a template. Students should compare it with their own implementation and edit anything that differs.
- The downloaded file is named `<roll-number>.pdf`.
