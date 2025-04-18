#!/bin/bash
echo "Redirecting to the project..."

cd ~/Desktop/PulseGuard || exit 1  # bail if it fails

touch start.sh

if [ -d "frontend" ]; then
  cd frontend
  sudo pnpm dev
else
  echo "💥 ERROR: 'frontend' folder not found!"
fi

